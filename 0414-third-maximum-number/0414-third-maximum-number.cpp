class Solution
{
	public:
		int thirdMax(vector<int> &nums)
		{
			
			set<int, greater < int>> s(nums.begin(), nums.end());
            int size = s.size();
			if (size < 3)
			{
				return *s.begin();
			}
			else
			{
				auto it = s.begin();
				advance(it, 2);
				
				return *it;
				
			}
        }
		};
