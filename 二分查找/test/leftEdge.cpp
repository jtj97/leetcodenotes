#include <vector>
#include <iostream>
using namespace std;

int findLeftEdge(vector<int>& nums, int target){
        int left = 0, right = nums.size();
        while(left<right){
            int mid = left + (right - left) / 2;
            if(nums[mid]==target){
                right = mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target){
                right = mid;
            }
        }
        return left;
}

int main(){
    vector<int> nums{1,2,2,4,5,6,7};
    int l = findLeftEdge(nums, 3);
    int l2 = findLeftEdge(nums, 2);
    cout<<l<<endl;
    cout<<l2<<endl;
    char c;
    cin>>c;
    return 0;
}