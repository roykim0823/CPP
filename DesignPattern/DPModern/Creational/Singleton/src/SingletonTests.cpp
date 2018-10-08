#include "Singleton.hpp"
#include <iostream>

using namespace std;
//#include <gtest/gtest.h>

//TEST(DatabaseTests, IsSingletonTest)
//{
//  auto& db = SingletonDatabase::get();
//  auto& db2 = SingletonDatabase::get();
//  ASSERT_EQ(1, db.instance_count);
//  ASSERT_EQ(1, db2.instance_count);
//}

/*
TEST(RecordFinderTests, SingletonTotalPopulationTest)
{
  SingletonRecordFinder rf;
  std::vector<std::string> names{ "Seoul", "Mexico City" };
  int tp = rf.total_population(names);
  EXPECT_EQ(17500000 + 17400000, tp);
}

TEST(RecordFinderTests, DependantTotalPopulationTest)
{
  DummyDatabase db{};
  ConfigurableRecordFinder rf{ db };
  EXPECT_EQ(4, rf.total_population(
    std::vector<std::string>{"alpha", "gamma"}));
}
*/

int main(int ac, char* av[])
{
//  testing::InitGoogleTest(&ac, av); 
//  return RUN_ALL_TESTS();
  //auto& db = SingletonDatabase::get();
  //auto& db2 = SingletonDatabase::get();
  //cout << db.instance_count << endl; 
  //cout << db2.instance_count << endl; 

  SingletonRecordFinder rf;
  std::vector<std::string> names {"Seoul", "Mexico City"};
  int tp = rf.total_population(names);
  cout << tp << endl;
  
  DummyDatabase db{};
  ConfigurableRecordFinder dummy_rf{ db };
  std::vector<std::string> dummy_names {"alpha", "gamma"};
  int dummy_tp = dummy_rf.total_population(dummy_names);
  cout << dummy_tp << endl;

  return 0;
}
