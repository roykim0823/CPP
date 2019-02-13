#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

struct Neuron
{
  vector<Neuron*> in, out;
  unsigned int id;

  Neuron() {
	  static int id=1;
	  this->id = id++;
  }

  template<typename T> 
  void connect_to(T& other);

  Neuron* begin() { return this; }
  Neuron* end()   { return this + 1; }

  friend ostream& operator<<(ostream& os, const Neuron &obj) {
	  for(Neuron* n : obj.in) 
		  os << n->id << "\t-->\t[" << obj.id << "]" << endl;
	  for(Neuron* n : obj.out) 
		  os << "[" << obj.id << "]\t-->\t" << n->id << endl;
	  return os;
  }
};

template<typename T>
void Neuron::connect_to(T& other) {
	out.push_back(&other); 	
	other.in.push_back(this);
}

struct NeuronLayer : vector<Neuron>
{
  NeuronLayer(int count)
  {
    while (count --> 0) 	// no '-->' operator; the postfix decrement and >
      emplace_back(Neuron{});
  }

  template<typename T> 
  void connect_to(T& other)
  {
    for (Neuron& from : *this)  	// use begin and end
      for (Neuron& to : other)
        from.connect_to(to);
  }

  friend ostream& operator<<(ostream& os, NeuronLayer& obj) {
	  for( auto &n : obj) 
		  os << n;
	  return os;
  }
};

int main()
{
  Neuron n1, n2;
  NeuronLayer layer1{3}, layer2{5};
  

  n1.connect_to(n2); 			// Neuron::connect_to<Neuron>
  cout << n1 << n2 << endl;
//  n1.connect_to(layer1); 		// not working
//  cout << n1 << layer1 << endl;
  layer1.connect_to(n1); 		// what we did begin()/end() for
  cout << layer1 << n1 << endl;
  layer1.connect_to(layer2); 	// NL::connect_to<T = NL>
  cout << layer1 << layer2 << endl;

  return 0;
}
