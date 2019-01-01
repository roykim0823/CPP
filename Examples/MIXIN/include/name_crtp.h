template<typename Printable>
struct RepeatPrint
{
    void repeat(unsigned int n) const
    {
        while (n-- > 0)
        {
            static_cast<Printable const&>(*this).print();
        }
    }
};
 
class Name : public RepeatPrint<Name>
{
public:
    Name(std::string firstName, std::string lastName)
      : firstName_(std::move(firstName))
      , lastName_(std::move(lastName)) {}
    
    void print() const
    {
        std::cout << lastName_ << ", " << firstName_ << '\n';
    }
    
private:
    std::string firstName_;
    std::string lastName_;
};
