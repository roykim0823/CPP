#include <string>
#include <tuple>

using UserInfo =               // type alias; see Item 9
  std::tuple<std::string,      // name
             std::string,      // email
             std::size_t> ;    // reputation

void tuple_access()
{
  UserInfo uInfo;                 // object of tuple type
  // ...
  auto val = std::get<1>(uInfo);  // get value of field 1
}

/*
 *   Here an unscoped enum is used to reference a field in a
 *   std::tuple - an improvement to numbered fields.
 *
 *   Since std::get requires a size_t, here we can take
 *   advantage of implicit conversion which would have otherwise
 *   be more effort using scoped enums.
 */
void unscoped_enum_useful()
{

  enum UserInfoFields { uiName, uiEmail, uiReputation };

  UserInfo uInfo;                       // as before
  // ...
  auto val = std::get<uiEmail>(uInfo);  // ah, get value of email field
}

/*
 *   The scoped enum method for referencing std::tuple
 *   field with an enum - requires a cast to size_t.
 *   Unscoped enums have an advantage here with implicit
 *   conversion.
 */
void scoped_enum()
{

  enum class UserInfoFields { uiName, uiEmail, uiReputation };

  UserInfo uInfo;                       // as before
  // ...
  auto val = std::get<static_cast<std::size_t>(UserInfoFields::uiEmail)>(uInfo);
}

/*
 * Key Idea:
 *
 *   Scoped enums require a cast to size_t type in order
 *   to reference a field in std::tuple. To create a helper
 *   function, use constexpr since std::get is a template.
 */
template<typename E>
constexpr typename std::underlying_type<E>::type
  toUType(E enumerator) noexcept
{
  return static_cast<typename std::underlying_type<E>::type>(enumerator);
}

void scoped_enum_helper()
{
  enum class UserInfoFields { uiName, uiEmail, uiReputation };

  UserInfo uInfo;                       // as before
  // ...
  auto val = std::get<toUType(UserInfoFields::uiEmail)>(uInfo);
}

int main() {
	tuple_access();
	unscoped_enum_useful();
	scoped_enum();
	scoped_enum_helper();
}
