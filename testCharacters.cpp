// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// STL
#include <sstream>
#include <fstream>
#include <string>
#include <list>
#include <iostream>
#include <memory>
#include <cassert>
// Boost
#include <boost/filesystem.hpp>
// Boost Unit Test Framework (UTF)
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#define BOOST_TEST_MODULE TestCharacters
#include <boost/test/unit_test.hpp>
// Characters
#include <Character.hpp>

namespace boost_utf = boost::unit_test;

// (Boost) Unit Test XML Report
std::ofstream utfReportStream ("TestCharacters_utfresults.xml");

/**
 * Configuration for the Boost Unit Test Framework (UTF)
 */
struct UnitTestConfig {
  /** Constructor. */
  UnitTestConfig() {
    boost_utf::unit_test_log.set_stream (utfReportStream);
    boost_utf::unit_test_log.set_format (boost_utf::OF_XML);
    boost_utf::unit_test_log.set_threshold_level (boost_utf::log_test_units);
  }

  /** Destructor. */
  ~UnitTestConfig() {
  }
};

// /////////////// Main: Unit Test Suite //////////////

// Set the UTF configuration (re-direct the output to a specific file)
BOOST_GLOBAL_FIXTURE (UnitTestConfig);

// Start the test suite
BOOST_AUTO_TEST_SUITE (master_test_suite)

/**
 * Test various ways to build Character objects
 */
BOOST_AUTO_TEST_CASE (characters1) {

  // Perso 1
  Character* p1_ptr = new Character ("Perceval", 35);
  assert (p1_ptr != nullptr);
  std::cout << "Perceval just built: " << *p1_ptr << std::endl;
  BOOST_CHECK_MESSAGE (p1_ptr->getAge() == 35,
                       "The age of this character should be 35");

  // Amend Perso 1
  assert (p1_ptr!=nullptr);
  p1_ptr->setAge(38);
  std::cout << "Perceval after age change: " << *p1_ptr << std::endl;

  BOOST_CHECK_MESSAGE (p1_ptr->getAge() == 38,
                       "The age of this character should be 38");

  // Cleaning
  delete p1_ptr; p1_ptr = nullptr;
}

// End the test suite
BOOST_AUTO_TEST_SUITE_END()
