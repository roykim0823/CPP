#pragma once

template <typename T> struct Property
{
  T value;
  Property(const T initialValue)
  {
    *this = initialValue;
  }

  operator T()
  {
	// perform some getter action
    return value;
  }

  T operator =(T newValue)
  {
	// perform some setter action
    return value = newValue;
  }
};
