// 问题要求把rand7映射到rand10 
// 本质上是个数学题, 有这样一个事实:
// if randX()、RandY()等概率地返回1-X、1-Y, 那么
// (randX() - 1)*Y + randY() 可以等概率的生成[1, X * Y]范围的随机数
// 时空效率还行
class Solution {
public:
    int rand10() {
        int n = (rand7() - 1)*7 + rand7();  // 等概率返回[1, 49], 丢弃后9个数
        while(n > 40)n = (rand7() - 1)*7 + rand7();
        return n%10 + 1;    // 取余返回0-9
    }
};