// mytime0.cpp  -- implementing Time methods
#include <iostream>
#include "mytime0.h"

//������Ĭ�Ϲ��캯����һ�����������Ĺ��캯��
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
1.const Time�������˷���ֵ���͡�
	sum�����Ǿֲ���������������ʱ�ᱻɾ����ʹ��const Time������ζ����sum��ɾ��ǰ�ṹ���俽����
	const���������������ֵ���޷����޸ĵĳ�����
	ע�⣺�ֲ�������Ϊ����ֵ��ʱ�򣬲�������Time &�����������أ���Ϊ���ָ��ľֲ������ں����������Ѿ����ͷ��ˡ�
2.const Time & t:ͨ�����õķ�ʽ���в������ݡ�
	�β�t����Ҫ��������ı�����ʵ���϶���ͬһ���ڴ�ռ����������֣������Զ�����в�������ʡ����Դ�����Ч�ʡ�
	��Ϊ��ʹ��ʵ�β����βε��޸Ķ��޸�����const���βν������ƣ��������䱻�޸�
3.����ĩβ��const:�������Ǹ�������Ա����
	���ó�����Ա�����Ķ���ĳ�Ա���ݣ��������ڸó�������ִ�й����б��޸ġ�
	���磺coding.Sum(fixing);
	coding�����ڵ���Sum(fixing)ʱ��coding�����е�hours��minutes�Ͳ������޸ģ����ں����ڼ���this->hours = 1;����

const������ֻ�ܹ�����const��Ա����
��������Ŀ���Ƕ�����ܻ���ó�Ա�����ù����оͿ����޸Ķ����ֵ�����������const��������κγ�Ա�������Ƿǳ�������ġ�
����Щ�϶������޸Ķ���ĸ�������ֵ�ĳ�Ա��������const˵�������������ڱ���ʱ��������������Щconst��Ա�������м�飬
���ȷʵû���޸Ķ���ֵ����Ϊ�������ͨ�����Ժ����һ��const�����������Щconst��Ա������ʱ�򣬱�������������

����const������Ϊʲô��ѡ���ڵ��ó�Ա����ʱ����麯���Ƿ��޸Ķ����ֵ������ѡ���ں���ĩβ����const�޶�����
���const������ĳ�Ա��������ε��ã���ôÿһ�ε���ʱ����Ҫ�Ժ����Ƿ��޸Ķ���ֵ�����ж��������ں���ĩβ����const�޶���֮��
ֻ��Ҫ�ں�����������н���һ���ж���֮���ٵ��øú���ʱ���������Ͳ���Ҫ���ж������Ƿ��޸���const������
*/

const Time Time::Sum(const Time & t) const
{
	//this->hours = 1;
    Time sum; //������һ��Time���͵Ķ���sum
    sum.minutes = minutes + t.minutes;
    sum.hours = hours + t.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}

void Time::Show() const
{
    std::cout << hours << " hours, " << minutes << " minutes";
}
