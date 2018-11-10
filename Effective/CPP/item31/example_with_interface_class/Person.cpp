//Person * Person::makePerson(const string& name,
std::shared_ptr<Person> Person::create(const string& name,
                            const Date& birthday,
                            const Address& addr,
                            const Country& country)
{
  //return new RealPerson(name, birthday, addr, country);
  //return std::shared_ptr<Person>(new RealPerson(name, birthday, addr, country));
  return std::make_shared<RealPerson>(name, birthday, addr, country);	// better than shared_ptr()
}
