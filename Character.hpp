#ifndef __CHARACTER_HPP
#define __CHARACTER_HPP

// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// STL
#include <string>

#include <Utilities.hpp>

class Character: public Utilities {
    protected:
        int m_age;
        std::string m_name;
    public:
      Character ();
      Character (const std::string& iName,
              const int& iAge);
      virtual ~Character();
      const int& getAge() const;
      const std::string& getName() const;
      void setAge(const int&);
      void setName(const std::string&);
    private:
      /**
       * Display of the object.
       *
       * @return std::string Dump of the object.
       */
      virtual std::string describe() const;
};
#endif // __CHARACTER_HPP

