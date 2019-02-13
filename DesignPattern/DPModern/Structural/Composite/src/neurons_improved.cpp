#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

struct Neuron;

template <typename Self>
struct SomeNeurons
{
  template <typename T> void connect_to(T& other)
  {
    for (Neuron& from : *static_cast<Self*>(this))
    {
      for (Neuron& to : other)
      {
        from.out.push_back(&to);
        to.in.push_back(&from);
      }
    }
  }
};

struct Neuron : SomeNeurons<Neuron>
{
  vector<Neuron*> in, out;
  unsigned int id;

  Neuron()
  {
    static int id = 1; 
    this->id = id++;
  }

  Neuron* begin() 	{ return this; }
  Neuron* end() 	{ return this + 1; }

  friend ostream& operator<<(ostream& os, const Neuron& obj)
  {
    for (Neuron* n : obj.in)
    {
      os << n->id << "\t-->\t[" << obj.id << "]" << endl;
    }

    for (Neuron* n : obj.out)
    {
      os << "[" << obj.id << "]\t-->\t" << n->id << endl;
    }
    return os;
  }
};

struct NeuronLayer : vector<Neuron>, SomeNeurons<NeuronLayer>
{
  NeuronLayer(int count)
  {
    while (count-- > 0)
      emplace_back(Neuron{});
  }

  friend ostream& operator<<(ostream& os, NeuronLayer& obj)
  {
    
    for (auto& n : obj) os << n;
    return os;
  }
};

int main()
{
  Neuron n1, n2;
  NeuronLayer layer1{3}, layer2{5};

  n1.connect_to(n2);
  cout << n1 << n2 << endl;
  n1.connect_to(layer1);
  cout << n1 << layer1 << endl;
  layer1.connect_to(n1);
  cout << layer1 << n1 << endl;
  layer1.connect_to(layer2);
  cout << layer1 << layer2 << endl;

  return 0;
}
