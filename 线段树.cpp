//线段树的构造
struct SegmentTreeNode {
public:
    int start, end, max;
    SegmentTreeNode *left, *right;
    SegmentTreeNode(int start, int end, int max) {
         this->start = start;
         this->end = end;
        this->max = max;
        this->left = this->right = NULL;
    }
}
class Solution {
public:
    /**
     *@param A: a list of integer
     *@return: The root of Segment Tree
     */
    SegmentTreeNode * build(vector<int>& A) {
        // write your code here
        int end = A.size()-1;
        if ( end < 0 ) {
            return nullptr;
        }
        if ( end == 0 ) {
            return new SegmentTreeNode( 0,0,A[0] );
        }
        int start = 0;
        
        return Recursivebuild(A,start,end);
    }
    SegmentTreeNode * Recursivebuild(vector<int>& A,int start, int end) {
        // write your code here
        if ( start > end ) {
            return nullptr;
        }
        SegmentTreeNode *root = new SegmentTreeNode(start,end);
        if ( start == end ) {
            root->max = A[start];
            return root;
        }
        root->left = Recursivebuild(A, start,(start+end)/2 );
        root->right = Recursivebuild(A, (start+end)/2+1,end);
        root->max = max( root->left->max, root->right->max );
        return root;
    }
};
class Solution {
public:
    /**
     *@param start, end: Denote an segment / interval
     *@return: The root of Segment Tree
     */
    SegmentTreeNode * build(int start, int end) {
        // write your code here
        if ( start > end ) {
            return nullptr;
        }
        SegmentTreeNode *root = new SegmentTreeNode(start,end);
        if( start == end ) {
            return root;
        }
        root->left = build( start,(start+end)/2 );
        root->right = build( (start+end)/2+1,end);
        return root;
    }
};
//线段树的查询
class Solution {
public:
    /**
     *@param root, start, end: The root of segment tree and 
     *                         an segment / interval
     *@return: The maximum number in the interval [start, end]
     */
    int query(SegmentTreeNode *root, int start, int end) {
        // write your code here
        if( root == nullptr ) {
            return 0x80000000;
        }
        end = min( end, root->end );
        start = max( start, root->start );
        return recursive( root, start, end );
        
    }
    int recursive( SegmentTreeNode *root, int start, int end) {
        int st = root->start, ed = root->end;
        if ( st == start && ed == end ) {
            return root->max;
        }
        if( start > st+(ed-st)/2 ) {
            return recursive( root->right,start,end );
        } else if ( end <= st+(ed-st)/2  ) {
            return recursive( root->left,start,end );
        } else {
            return max( recursive( root->left,start,st+(ed-st)/2 ), recursive( root->right,1+st+(ed-st)/2,end ) );
        }
    }
};
//线段树的修改
class Solution {
public:
    /**
     *@param root, index, value: The root of segment tree and 
     *@ change the node's value with [index, index] to the new given value
     *@return: void
     */
    void modify(SegmentTreeNode *root, int index, int value) {
        // write your code here
        if( root == nullptr || index < root->start || index > root->end) {
            return ;
        }
        recursive( root, index, value);
    }
    int recursive( SegmentTreeNode *root, int index,int val) {
        int st = root->start, ed = root->end;
        if ( st == ed ) {
            root->max = val;
            return val;
        }
        if( index > st+(ed-st)/2 ) {
            recursive( root->right,index,val);
        } else if ( index <= st+(ed-st)/2  ) {
            recursive( root->left,index ,val);
        } else {
            recursive( root->left, index , val);
            recursive( root->right, index, val);
        }
        root->max = max( root->right->max, root->left->max );
        return root->max;
    }
};

