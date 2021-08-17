#ifndef CODE_KATA_SGN_H
#define CODE_KATA_SGN_H

// This function calculates the sign of the passed value in a typesafe way.
//  val < 0     => -1
//  val == 0    =>  0
//  val > 0     => +1
template <typename T>
int sgn(T val)
{
    return (T(0) < val) - (val < T(0));
}


#endif // CODE_KATA_SGN_H
