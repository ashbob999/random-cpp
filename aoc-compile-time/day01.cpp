
#include <utility>
#include <vector>
#include <cstdint>
#include <unordered_set>
#include <algorithm>
#include <array>
#include <iostream>

#define add_zero(A) A "\0"

using namespace std;

template<typename T>
constexpr T numericParse(char*& p)
{
	bool have = false;
	T n = 0;
	for (; *p != '\0'; p++)
	{
		T d = *p - '0';
		if (d >= 0 && d <= 9)
		{
			n = 10 * n + d;
			have = true;
		}
		else if (have)
		{
			return n;
		}
	}
	if (have)
	{
		return n;
	}
	return 0;
}

template<class T>
constexpr T const_abs(T value)
{
	if (value < 0)
	{
		return value * -1;
	}
	return value;
}

constexpr pair<long, long> solve()
{
	long long part1 = 0, part2 = 0;

	const char* input_og = add_zero(INPUT);
	char* input = (char*) &input_og[0];

	vector<pair<bool, int32_t>> dirs;

	// parse input
	while (*input != '\0')
	{
		pair<bool, int32_t> dir;

		if (*input == 'L')
		{
			dir.first = true;
		}
		else
		{
			dir.first = false;
		}

		input++;

		dir.second = numericParse<int32_t>(input);

		dirs.push_back(dir);

		if (*input == '\n')
		{
			break;
		}
		input += 2; // skip ", "
	}

	// part 1
	array<int, 2> pos = { 0, 0 };
	int facing = 0;

	for (auto& dir : dirs)
	{
		if (dir.first)
		{
			facing--;
		}
		else
		{
			facing++;
		}

		facing %= 4;
		facing += (facing < 0) ? 4 : 0;

		int index = 1;

		if (facing % 2 == 0)
		{
			index = 0;
		}

		int sign = -1;

		if (facing <= 1)
		{
			sign = 1;
		}

		pos[index] += dir.second * sign;
	}

	part1 = const_abs(pos[0]) + const_abs(pos[1]);

	// part 2
	pos = { 0, 0 };
	facing = 0;
	vector<array<int, 2>> visited;
	visited.push_back(pos);

	for (auto& dir : dirs)
	{
		if (dir.first)
		{
			facing--;
		}
		else
		{
			facing++;
		}

		facing %= 4;
		facing += (facing < 0) ? 4 : 0;

		int index = 1;

		if (facing % 2 == 0)
		{
			index = 0;
		}

		int sign = -1;

		if (facing <= 1)
		{
			sign = 1;
		}

		bool found = false;

		for (int i = 0; i < dir.second; i++)
		{
			pos[index] += sign;
			auto f = find(visited.begin(), visited.end(), pos);
			if (f != visited.end())
			{
				found = true;
				break;
			}
			else
			{
				visited.push_back(pos);
			}
		}

		if (found)
		{
			break;
		}
	}

	part2 = const_abs(pos[0]) + const_abs(pos[1]);

	return { part1, part2 };
}


int main()
{
	constexpr pair<long, long> result = solve();

	cout << "Advent Of Code 2016 Day 01" << endl;
	cout << "Part 1: " << result.first << endl;
	cout << "Part 2: " << result.second << endl;

	return 0;
}
