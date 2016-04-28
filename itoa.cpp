string itoa(int i)
    {
        string re;
        if( i == 0 ) {
            re.push_back('0');
            return re;
        }
        bool neg = false;
        long long ti = i;
        if ( ti < 0 ) {
            neg = true;
            ti = -ti;
        }
        
        while(ti!=0)
        {
            re.push_back( (char)(ti%10 + '0') );
            ti /= 10;
        }
        if ( neg ) {
            re.push_back('-');
        }
        int start=0,end=re.length()-1;
        char temp;
        while(start<end)
        {
            temp = re[start];
            re[start]=re[end];
            re[end] = temp;
            start++,end--;
        }
        return re;
    }