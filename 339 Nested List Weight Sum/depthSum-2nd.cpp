/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

 // 4 ms, faster than 71.26%
class Solution {
private:
    int sum = 0;
    void depthS(vector<NestedInteger>& list, int depth){
        for(int i = 0; i < list.size(); i++ ){
            if( list[i].isInteger() )
                sum += depth * list[i].getInteger();
            else
                depthS( list[i].getList(), depth + 1);
        }
    }
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        depthS( nestedList, 1);
        return sum;
    }
};