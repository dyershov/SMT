/*
 * (c) Dmitry Yershov
 */

#ifndef TASK_HPP_
#define TASK_HPP_

template<typename Output_, typename ...Input_>
class Task
{
public:
    using Input = std::tuple<Input_...>;
    using Output = Output_;

    Task(Output_ (*)(Input_...) function) :
        f_ptr(function)
    {
    }

    Output_ operator(Input_... args)
    {
        return f_ptr(args...)
    }



private:
    Output_ (*)(Input_) f_ptr;
}

#endif
