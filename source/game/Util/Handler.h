#pragma once

template <class... TArgs>
class Handler
{
public:
    virtual void Call(TArgs...) = 0;
};

template <class TObject, class... TArgs>
class HandlerPTMF : public Handler<TArgs...>
{
    TObject* m_object;
    u32 m_delta;
    void (TObject::*m_function)(TArgs...);

public:
    HandlerPTMF(TObject* object, void (TObject::*function)(TArgs...))
    {
        m_delta = 0x1;
        m_object = object;
        m_function = function;
    }

    virtual void Call(TArgs... args)
    {
        (m_object->*m_function)(args...);
    }
};

class HandlerDummy
{
};

static_assert(sizeof(HandlerPTMF<HandlerDummy, u32>) == 0x14);

// Hacky compatibility between CW and Clang, by patching the CW PTMF functions
template <class TObject>
class PTMF
{
public:
    PTMF() = default;

    PTMF(void (TObject::*function)())
    {
        m_delta = 0x1;
        m_function = function;
    }

private:
    u32 m_delta;
    void (TObject::*m_function)();
};

template <class TObject, class... TArgs>
class PTMFArg
{
public:
    PTMFArg() = default;

    PTMFArg(void (TObject::*function)(TArgs...))
    {
        m_delta = 0x1;
        m_function = function;
    }

private:
    u32 m_delta;
    void (TObject::*m_function)(TArgs...);
};
