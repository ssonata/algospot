#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MIN_VALUE 1415.0000000000
#define MAXMAX 9999999999
unsigned int number_of_city = 0;
int result[16];
double result_sum = MAXMAX;

void update(vector<vector<double>>& city)
{
    double sum = 0;
    for(int i = 1; i < number_of_city; i++)
    {
        sum += city[result[i-1]][result[i]];
    }

    if(sum < result_sum)
    {
        result_sum = sum;
    }
	return;
}


void check_it(int depth, vector<vector<double>>& city)
{
    int i, j;
    int is_pass = 0;

    for(i=0; i<3; i++)
    {
        is_pass = 0;

        for(j=0; j<depth; j++)
        {
            if(result[j] == i)
            {
                is_pass = 1;
                break;
            }
        }

        if(is_pass == 1)
        {
            continue;
        }

        result[depth] = i;
        if(depth+1 == 3)
        {
            update(city);
        }
        else
        {
            check_it(depth+1, city);
        }
    }
	return ;
}
void init(vector<vector<double>>& city)
{
	result_sum = MAXMAX;
	city.clear();
	return;
}

int main()
{
	cout<<fixed;
	cout.precision(10);
	int loop;
	vector<double> output;
	cin >> loop;

	if(loop > 50 || loop <= 0 )
	{
		return 0;
	}
	for(int i = 0; i < loop ; i++)
	{
		cin >> number_of_city;
		if(number_of_city < 3 || number_of_city > 8)
		{
			return 0;
		}

		vector<vector<double> >city(number_of_city, vector<double>(number_of_city, 0));
		for(int j = 0; j < number_of_city; j++)
		{
			for(int k = 0; k < number_of_city; k++)
			{
				cin >> city[j][k];
				if(city[j][k] < 0 || city[j][k] > MIN_VALUE)
				{
					return 0;
				}
				if(j == k  && city[j][k] != 0)
				{
					return 0;
				}
			}
			cout<<endl;
		}
		check_it(0, city);
		output.push_back(result_sum);
		init(city);
	}

	vector<double>::iterator iter = output.begin();
	for(; iter != output.end(); ++iter)
	{
		cout<<*iter<<endl;
	}
	return 0;
}
