class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function


    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        
        priority_queue<int> pq;
        //step 1 creation of heap
        for(int i = l;i<k;i++){
            pq.push(arr[i]);
        }
        
        // step 2 insertion of elements
            
        for(int i=k;i<=r;i++){
            if(arr[i] < pq.top())
           { pq.pop();
            pq.push(arr[i]);
        }
        }
        
        int ans = pq.top();
        
        return ans;
        
        
        
    }
};