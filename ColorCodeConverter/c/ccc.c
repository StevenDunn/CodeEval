// color code converter soln in c for code eval by steven a dunn

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int rgb[3];

float hue2rgb(float, float, float);
void hsl2rgb(char*);
void hsv2rgb(char*);
void cmyk2rgb(char*);
void hex2rgb(char*);

int main (int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[512];
        while (fgets(line, sizeof(line), fp))
        {
            char* match = strstr(line, "HSL");
            if (match)
                hsl2rgb(line);
            else
            {
                match = strstr(line, "HSV");
                if (match)
                    hsv2rgb(line);
                else if (line[0] == '(')
                    cmyk2rgb(line);
                else if (line[0] == '#')
                    hex2rgb(line);
                else
                    continue;
            }
            printf("RGB(%d,%d,%d)\n", rgb[0], rgb[1], rgb[2]);
        }
        fclose(fp);
    }
    return 0;
}

float hue2rgb(float p, float q, float t)
{
    if (t < 0)
        t += 1;
    if (t > 1)
        t -= 1;
    if (t < 1/6.0)
        return p + (q - p) * 6 * t;
    if (t < 1/2.0)
        return q;
    if (t < 2/3.0)
        return p + (q - p) * (2/3.0 - t) * 6;
    return p;
}

void hsl2rgb(char* line)
{
    float hsl[3];
    int hsl_idx = 0;
    char *line_start = line + 4;
    char *token = strtok(line_start, ",)");
    while (token != NULL)
    {
        hsl[hsl_idx] = atof(token);
        if (++hsl_idx > 2)
            break;
        token = strtok(NULL, ",)");
    }

    float h = hsl[0]/360.0;
    float s = hsl[1]/100.0;
    float l = hsl[2]/100.0;

    float q = 0.0;
    float p = 0.0;
    if (l < 0.5)
        q = l * (1 + s);
    else
        q = l + s - l * s;
    p = 2 * l - q;

    float r, g, b;
    r = hue2rgb(p, q, h + 1/3.0);
    g = hue2rgb(p, q, h);
    b = hue2rgb(p, q, h - 1/3.0);

    rgb[0] = round(r * 255);
    rgb[1] = round(g * 255);
    rgb[2] = round(b * 255);
}

void hsv2rgb(char* line)
{
    float hsv[3];
    int hsv_idx = 0;
    char *line_start = line + 4;
    char *token = strtok(line_start, ",)");
    while (token != NULL)
    {
        hsv[hsv_idx] = atof(token);
        if (++hsv_idx > 2)
            break;
        token = strtok(NULL, ",)");
    }

    float hue = hsv[0]/360;
    float saturation = hsv[1]/100;
    float value = hsv[2]/100;

    int i = floor(hue * 6);
    float f = (hue * 6) - i;
    float p = value * (1 - saturation);
    float q = value * (1 - f * saturation);
    float t = value * (1 - (1 - f) * saturation);

    float r, g, b;
    switch (i % 6)
    {
        case 0:
            r = value;
            g = t;
            b = p;
            break;
        case 1:
            r = q;
            g = value;
            b = p;
            break;
        case 2:
            r = p;
            g = value;
            b = t;
            break;
        case 3:
            r = p;
            g = q;
            b = value;
            break;
        case 4:
            r = t;
            g = p;
            b = value;
            break;
        case 5:
            r = value;
            g = p;
            b = q;
            break;
        default:
            break;
    }

    rgb[0] = round(r * 255);
    rgb[1] = round(g * 255);
    rgb[2] = round(b * 255);
}

void cmyk2rgb(char* line)
{
    float cmyk[4];
    int cmyk_idx = 0;
    char *line_start = line + 1;
    char *token = strtok(line_start, ",)");
    while (token != NULL)
    {
        cmyk[cmyk_idx] = atof(token);
        if (++cmyk_idx > 3)
            break;
        token = strtok(NULL, ",)");
    }

    float c, m, y, k;
    c = cmyk[0];
    m = cmyk[1];
    y = cmyk[2];
    k = cmyk[3];

    float r, g, b;
    r = 255 * (1 - c) * (1 - k);
    g = 255 * (1 - m) * (1 - k);
    b = 255 * (1 - y) * (1 - k);

    rgb[0] = round(r);
    rgb[1] = round(g);
    rgb[2] = round(b);
}

void hex2rgb(char* line)
{
    ++line;
    char sub[2];
    char *end;

    memcpy(sub, &line[0],2);
    rgb[0] = strtol(sub, &end, 16);

    memcpy(sub, &line[2], 2);
    rgb[1] = strtol(sub, &end, 16);

    memcpy(sub, &line[4], 2);
    rgb[2] = strtol(sub, &end, 16);
}