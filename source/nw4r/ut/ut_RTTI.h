#pragma once

namespace nw4r::ut::detail
{

class RuntimeTypeInfo
{
public:
    // Constructor invoked by sinit
    RuntimeTypeInfo(const RuntimeTypeInfo* parent)
      : m_parent(parent)
    {
    }

    const RuntimeTypeInfo* m_parent;

protected:
    bool IsDerivedFrom(const RuntimeTypeInfo* base) const
    {
        for (const RuntimeTypeInfo* info = this; info != nullptr;
             info = info->m_parent) {
            if (info == base)
                return true;
        }
        return false;
    }

    template <class T>
    static const RuntimeTypeInfo* GetRuntimeTypeInfo(T* obj)
    {
        return &T::typeInfo;
    }

public:
    template <class Derived, class Base>
    static Derived cast(Base* base)
    {
        if (base != nullptr && base->GetRuntimeTypeInfo()->IsDerivedFrom(GetRuntimeTypeInfo((Derived) nullptr))) {
            return reinterpret_cast<Derived>(base);
        }
        return nullptr;
    }
};

#define INSTANTIATE_TYPEINFO                                                   \
  virtual const nw4r::ut::detail::RuntimeTypeInfo* GetRuntimeTypeInfo()        \
    override                                                                   \
  {                                                                            \
    return &typeInfo;                                                          \
  }                                                                            \
  static const nw4r::ut::detail::RuntimeTypeInfo typeInfo

#define TYPEINFO_DERIVED(obj, base)                                            \
  const nw4r::ut::detail::RuntimeTypeInfo obj::typeInfo(&base::typeInfo)
#define TYPEINFO_ROOT(obj)                                                     \
  const nw4r::ut::detail::RuntimeTypeInfo obj::typeInfo(nullptr)

} // namespace nw4r::ut::detail
