#include <bits/stdc++.h> 
long long sumOfMaxAndMin(vector<int> &nums, int n, int k) {
	// Write your code here.
 long long min_sum = 0;
 long long max_sum = 0;
 int index_max;
 int index_min = 0;
 int max = 0;
 int min = nums[0];
 
for(int i=0;i<k;i++){
 
if(nums[i]>max){
	max= nums[i];
	index_max = i; 
	 
}

if(nums[i]<min){
	min = nums[i];
	index_min = i; 
}

}
max_sum += max;
min_sum += min; 

for(int i =k; i<n;i++){

if(index_max <i-k+1){
	max = 0;
for(int j = i-k+1;j<=i;j++){
 
if(nums[j]>max){
	max= nums[j];
	index_max = j; 
	 
}


}

 

}

if(index_min <i-k+1){
	min = nums[i-k+1];
	index_min = i-k+1;
	
for(int j=i-k+2;j<=i;j++){
 
if(nums[j]<min){
	min = nums[j];
	index_min = j; 
}

}


}


if(nums[i] > max){
	max = nums[i];
	index_max = i;
	

}
           
if(nums[i] < min){
	min = nums[i];
	index_min = i;
	
	
}
max_sum += max;
min_sum += min;

}


long long sum = max_sum + min_sum;

return sum;








	
}




