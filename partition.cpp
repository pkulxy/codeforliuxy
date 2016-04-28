/*
    *快排的一次分划，以target值为准，大于等于target的元素在右
    *小于target的元素在左边
    *返回分划后第一个大于等于target的元素下标
    */
    int partition( vector<int> &nums, int start, int end , int target) {
        if ( start > end ) {
            return -1;
        }
        int i = start, j = end-1;
        while ( i < j ) {
            while ( i < end && nums[i] < target ) ++i;
            while ( j >= start && nums[j] >= target ) --j;
            if ( i < j ) {
                swap( nums[i], nums[j] );
            }
        }
        return i;
    }
	//返回分划位置的末尾
	int partition(vector<int>&nums,int start,int end)  
    {  
        int x =  (start+end)/2;  
        swap(nums[start],nums[x]);  
        int i = start+1;  
        int j = i;  
        while(i<=end&&j<=end)  
        {  
            if(nums[j]<nums[start])  
            {  
                swap(nums[i],nums[j]);  
                i++;  
            }  
            j++;  
        }  
        swap(nums[start],nums[i-1]);  
        return i-1;  
    }  
};