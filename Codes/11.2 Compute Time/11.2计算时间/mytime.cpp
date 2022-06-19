// mytime0.cpp  -- implementing Time methods
#include <iostream>
#include "mytime0.h"

//定义了默认构造函数和一个包含参数的构造函数
Time::Time()
{
    hours = minutes = 0;
}

Time::Time(int h, int m )
{
    hours = h;
    minutes = m;
}

void Time::AddMin(int m)
{
    minutes += m;
    hours += minutes / 60;
    minutes %= 60;
}

void Time::AddHr(int h)
{
    hours += h;
}

void Time::Reset(int h, int m)
{
    hours = h;
    minutes = m;
}


/*
1.const Time：定义了返回值类型。
	sum对象是局部变量，函数结束时会被删除，使用const Time类型意味着在sum被删除前会构造其拷贝。
	const定义了这个拷贝的值是无法被修改的常量。
	注意：局部变量作为返回值的时候，不允许以Time &的类型来返回，因为这个指向的局部变量在函数结束后已经被释放了。
2.const Time & t:通过引用的方式进行参数传递。
	形参t是需要传入参数的别名，实际上对于同一块内存空间有两个名字，都可以对其进行操作，节省了资源提高了效率。
	但为了使得实参不受形参的修改而修改利用const对形参进行限制，不允许其被修改
3.函数末尾的const:表面这是个常量成员函数
	调用常量成员函数的对象的成员数据，不允许在该常量函数执行过程中被修改。
	例如：coding.Sum(fixing);
	coding对象在调用Sum(fixing)时，coding对象中的hours和minutes就不允许被修改，可在函数内加入this->hours = 1;测试

const常对象只能够调用const成员函数
这样做的目的是对象可能会调用成员，调用过程中就可能修改对象的值。如果不允许const对象调用任何成员函数又是非常不合理的。
把那些肯定不会修改对象的各个属性值的成员函数加上const说明符，这样，在编译时，编译器将对这些const成员函数进行检查，
如果确实没有修改对象值的行为，则检验通过。以后，如果一个const常对象调用这些const成员函数的时候，编译器将会允许。

对于const常对象，为什么不选择在调用成员函数时来检查函数是否修改对象的值，而是选择在函数末尾加上const限定符？
如果const常对象的成员函数被多次调用，那么每一次调用时都需要对函数是否修改对象值进行判定。但当在函数末尾加上const限定符之后，
只需要在函数编译过程中进行一次判定，之后再调用该函数时，编译器就不需要在判定函数是否修改了const对象了
*/

const Time Time::Sum(const Time & t) const
{
	//this->hours = 1;
    Time sum; //创建了一个Time类型的对象sum
    sum.minutes = minutes + t.minutes;
    sum.hours = hours + t.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}

void Time::Show() const
{
    std::cout << hours << " hours, " << minutes << " minutes";
}
