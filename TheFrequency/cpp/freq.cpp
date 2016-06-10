// the frequency soln in cpp for code eval by steven a dunn

#include <complex>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <valarray>
#include <vector>

using std::complex;
using std::ifstream;
using std::istringstream;
using std::polar;
using std::string;
using std::valarray;
using std::vector;

const double PI = 3.141592653589793238460;

typedef complex<double> Complex;
typedef vector<Complex> CArray;

vector<float> tokenize(string);
float sum(vector<float>);
void fft(CArray&);
float max(vector<float>);

int main (int argc, char* const argv[])
{
	ifstream input_file(argv[1]);
	string line;

	if (input_file)
	{
		while (getline(input_file, line))
		{
			vector<float> samples = tokenize(line);
			float sample_mean = sum(samples) / samples.size();
			for (int i = 0; i < samples.size(); ++i)
				samples[i] -= sample_mean;

			CArray x;
			for (int i = 0; i < samples.size(); ++i)
				x.push_back(Complex(samples[i]));
			fft(x);
			for (int i = 0; i < x.size(); ++i)
    			samples[i] = fabs(x[i].real());
			
			float max_val = max(samples);
			int max_idx = -1;
			for (int i = 0; i < samples.size(); ++i)
				if (samples[i] == max_val)
				{
					max_idx = i;
					break;
				}
			int sampling_frequency = 20000;
			int frequency = max_idx * sampling_frequency / samples.size();
			printf("%d \n", frequency);
		}
		input_file.close();
	}
	return 0;
}

vector<float> tokenize(string line)
{
	vector<float> tokens;
	istringstream iss(line);
	string token;

	while (getline(iss, token, ' '))
		tokens.push_back(atof(token.c_str()));

	return tokens;
}

float sum (vector<float> tokens)
{
	float sum = 0;
	for (int i = 0; i < tokens.size(); ++i)
		sum += tokens[i];
	return sum;
}

void fft(CArray& x)
{
	CArray r;
    int N = x.size();
    int M;
    if (N % 2)
    	M = N / 2 + 1; 
    else 
    	M = N / 2;

    for (int n = 0; n < M; ++n)
    {
        Complex s(0.0, 0.0);
        for (int k = 0; k < N; ++k) 
        {
            float tmp = 2 * PI * k * n / N;
            s += x[k] * (cos(tmp) - Complex(0.0, 1.0) * sin(tmp));
        }
        r.push_back(s);
    }
   	x = r;
}

/*
// algorithm modified from: http://rosettacode.org/wiki/Fast_Fourier_transform#C.2B.2B
void fft(CArray& x)
{
    const size_t N = x.size();
    if (N <= 1) return;
 	
    // divide
    CArray even;
    for (int i = 0; i < N; i+=2)
    	even.push_back(x[i]);
    CArray odd;
    for (int i = 1; i < N; i+=2)
    	odd.push_back(x[i]);

    // conquer
    fft(even);
    fft(odd);
 
    // combine
    for (size_t k = 0; k < N/2; ++k)
    {
        Complex t = polar(1.0, -2 * PI * k / N) * odd[k];
        x[k    ] = even[k] + t;
        x[k+N/2] = even[k] - t;
    }
}
 */

float max(vector<float> tokens)
{
	float max = tokens[0];
	for (int i = 1; i < tokens.size(); ++i)
		if (tokens[i] > max)
			max = tokens[i];
	return max;
}