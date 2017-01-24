/*
 * (c) Dmitry Yershov
 */

#ifndef TASK_HPP_
#define TASK_HPP_

#include <tuple>

template<typename>
class Task; // undefined


template<typename Output_, typename... Input_>
class Task<Output_(Input_...)>
{
public:
    using Input = std::tuple<Input_...>;
    using Output = Output_;

    Task() :
        f_ptr(nullptr)
    {
    }

    Task(Output_ (*function)(Input_...)) :
        f_ptr(function)
    {
    }

    Task& operator=(Output_ (*function)(Input_...))
    {
        f_ptr = function;
        return *this;
    }

    Task& operator=(Task t)
    {
        f_ptr = t.f_ptr;
        return *this;
    }

    Output_ operator() (Input_... args)
    {
        return f_ptr(args...);
    }



private:
    Output_ (*f_ptr)(Input_...);
};

#endif
