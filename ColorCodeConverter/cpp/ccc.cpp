// color code converter soln in cpp for code eval by steven a dunn

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::hex;
using std::ifstream;
using std::istringstream;
using std::string;
using std::stringstream;
using std::vector;

static int rgb[3];

vector<float> parse(string);

float hue2rgb(float, float, float);
void hsl2rgb(string);
void hsv2rgb(string);
void cmyk2rgb(string);
int convert(string);
void hex2rgb(string);

int main (int argc, char* const argv[])
{
    ifstream input_file(argv[1]);
    string line;

    if (input_file)
    {
        while (getline(input_file, line))
        {

            string match = line.substr(0, 3);
            if (match == "HSL")
                hsl2rgb(line);
            else if (match == "HSV")
                hsv2rgb(line);
            else if (match[0] == '(')
                cmyk2rgb(line);
            else if (match[0] == '#')
                hex2rgb(line);
            else
                continue;
            cout << "RGB(" << rgb[0] << "," << rgb[1] << "," << rgb[2] << ")" << endl;

        }
        input_file.close();
    }
}

vector<float> parse(string input)
{
    istringstream iss(input);
    string line;
    vector<float> tokens;
    while (getline(iss, line, ','))
        tokens.push_back(atof(line.c_str()));
    return tokens;
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

void hsl2rgb(string line)
{
    vector<float> vals = parse(line.substr(4, line.size() - 5));
    float h = vals[0]/360.0;
    float s = vals[1]/100.0;
    float l = vals[2]/100.0;

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

void hsv2rgb(string line)
{
    vector<float> vals = parse(line.substr(4, line.size() - 5));
    float hue = vals[0]/360;
    float saturation = vals[1]/100;
    float value = vals[2]/100;

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

void cmyk2rgb(string line)
{
    vector<float> vals = parse(line.substr(1, line.size() - 1));
    float c, m, y, k;
    c = vals[0];
    m = vals[1];
    y = vals[2];
    k = vals[3];

    float r, g, b;
    r = 255 * (1 - c) * (1 - k);
    g = 255 * (1 - m) * (1 - k);
    b = 255 * (1 - y) * (1 - k);

    rgb[0] = round(r);
    rgb[1] = round(g);
    rgb[2] = round(b);
}

int convert(string line)
{
    stringstream ss;
    int x;
    ss << hex << line;
    ss >> x;
    return x;
}

void hex2rgb(string line)
{
    line = line.substr(1);
    int r, g, b;
    rgb[0] = convert(line.substr(0, 2));
    rgb[1] = convert(line.substr(2, 2));
    rgb[2] = convert(line.substr(4, 2));
}