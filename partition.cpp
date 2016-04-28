/*
    *���ŵ�һ�ηֻ�����targetֵΪ׼�����ڵ���target��Ԫ������
    *С��target��Ԫ�������
    *���طֻ����һ�����ڵ���target��Ԫ���±�
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
	//���طֻ�λ�õ�ĩβ
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