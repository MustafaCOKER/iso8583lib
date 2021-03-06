#ifndef ISOMESSAGEFIELD_H
#define ISOMESSAGEFIELD_H

#include <string>

using std::string;
using std::to_string;

#include "IsoMessageFieldBase.h"

template<class T, size_t maxSize>
class IsoMessageField: public IsoMessageFieldBase
{
    public:
        IsoMessageField();
        IsoMessageField(T val, std::string sName);

        void set(T val);
        T get(void);

        virtual string getField() override;

        virtual ~IsoMessageField();

    private:
        T _value;
        const size_t _maxSize{maxSize};
};

template<class T, size_t maxSize>
IsoMessageField<T, maxSize>::IsoMessageField()
    : _value( T() )//, _maxSize( maxSize )
{
    // IsoMessageFieldBase();
}

template<class T, size_t maxSize>
IsoMessageField<T, maxSize>::IsoMessageField(T val, std::string sName)
    : _value(val)//, _maxSize( maxSize )
{
    // IsoMessageFieldBase(sName);
}

template<class T, size_t maxSize>
void IsoMessageField<T, maxSize>::set(T val)
{
    _value = val;
}

template<class T, size_t maxSize>
T IsoMessageField<T, maxSize>::get(void)
{
    return _value;
}

template<class T, size_t maxSize>
string IsoMessageField<T, maxSize>::getField()
{
    return _formatter( to_string(_value) );
}

template<class T, size_t maxSize>
IsoMessageField<T, maxSize>::~IsoMessageField()
{ /* */ }


#endif // ISOMESSAGEFIELD_H
