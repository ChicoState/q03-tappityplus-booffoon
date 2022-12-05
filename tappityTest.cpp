/**
 * Unit Test suite
**/

#include <gtest/gtest.h>
#include "tappity.h"

class tappityTest : public ::testing::Test
{
	protected:
		tappityTest(){}
		virtual ~tappityTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(tappityTest, smoketest)
{
	ASSERT_TRUE(true);
}


TEST(tappityTest, length_both_empty)
{
  tappity tap("");
  tap.entry("");
  int difference = tap.length_difference();
	ASSERT_EQ(difference, 0);
}

TEST(tappityTest, length_both_same)
{
  tappity tap("asd");
  tap.entry("fgh");
  int difference = tap.length_difference();
	ASSERT_EQ(difference, 0);
}

TEST(tappityTest, length_reference_larger)
{
  tappity tap("12345");
  tap.entry("67");
  int difference = tap.length_difference();
	ASSERT_EQ(difference, 3);
}

TEST(tappityTest, length_input_larger)
{
  tappity tap("12");
  tap.entry("34567");
  int difference = tap.length_difference();
	ASSERT_EQ(difference, 3);
}

TEST(tappityTest, length_reference_empty)
{
  tappity tap("");
  tap.entry("asdf");
  int difference = tap.length_difference();
	ASSERT_EQ(difference, 4);
}

TEST(tappityTest, length_input_empty)
{
  tappity tap("asdf");
  tap.entry("");
  int difference = tap.length_difference();
	ASSERT_EQ(difference, 4);
}

TEST(tappityTest, accuracy_both_empty)
{
  tappity tap("");
  tap.entry("");
  double accuracyPercent = tap.accuracy();
	ASSERT_EQ(accuracyPercent, 100);
}

TEST(tappityTest, accuracy_input_empty)
{
  tappity tap("asd");
  tap.entry("");
  double accuracyPercent = tap.accuracy();
	ASSERT_EQ(accuracyPercent, 0.0);
}

TEST(tappityTest, accuracy_reference_empty)
{
  tappity tap("");
  tap.entry("asd");
  double accuracyPercent = tap.accuracy();
	ASSERT_EQ(accuracyPercent, 0.0);
}

TEST(tappityTest, accuracy_one_character_same)
{
  tappity tap("a");
  tap.entry("a");
  double accuracyPercent = tap.accuracy();
	ASSERT_EQ(accuracyPercent, 100);
}

TEST(tappityTest, accuracy_one_character_different)
{
  tappity tap("a");
  tap.entry("b");
  double accuracyPercent = tap.accuracy();
	ASSERT_EQ(accuracyPercent, 0.0);
}

TEST(tappityTest, accuracy_string_full_match)
{
  tappity tap("test");
  tap.entry("test");
  double accuracyPercent = tap.accuracy();
	ASSERT_EQ(accuracyPercent, 100);
}

TEST(tappityTest, accuracy_string_no_match)
{
  tappity tap("1234");
  tap.entry("test");
  double accuracyPercent = tap.accuracy();
	ASSERT_EQ(accuracyPercent, 0);
}

TEST(tappityTest, accuracy_input_larger)
{
  tappity tap("a");
  tap.entry("asdf");
  double accuracyPercent = tap.accuracy();
	ASSERT_EQ(accuracyPercent, 25.0);
}

TEST(tappityTest, accuracy_reference_larger)
{
  tappity tap("asdf");
  tap.entry("a");
  double accuracyPercent = tap.accuracy();
	ASSERT_EQ(accuracyPercent, 25.0);
}

TEST(tappityTest, accuracy_all_repeating_same)
{
  tappity tap("aaaaaaaaaa");
  tap.entry("aaaaaaaaaa");
  double accuracyPercent = tap.accuracy();
	ASSERT_EQ(accuracyPercent, 100);
}

TEST(tappityTest, accuracy_all_repeating_different)
{
  tappity tap("aaaaaaaaaa");
  tap.entry("bbbbbbbbbb");
  double accuracyPercent = tap.accuracy();
	ASSERT_EQ(accuracyPercent, 0);
}

TEST(tappityTest, accuracy_begginning_matching)
{
  tappity tap("ddasasasas");
  tap.entry("ddopopopop");
  double accuracyPercent = tap.accuracy();
	ASSERT_EQ(accuracyPercent, 20);
}

TEST(tappityTest, accuracy_middle_matching)
{
  tappity tap("asasddasas");
  tap.entry("opopddopop");
  double accuracyPercent = tap.accuracy();
	ASSERT_EQ(accuracyPercent, 20);
}

TEST(tappityTest, accuracy_ending_matching)
{
  tappity tap("asasasasdd");
  tap.entry("opopopopdd");
  double accuracyPercent = tap.accuracy();
	ASSERT_EQ(accuracyPercent, 20);
}

TEST(tappityTest, accuracy_long_words)
{
  tappity tap("aaaaehhhheppppeuuuuee");
  tap.entry("xxxxebbbbennnnemmmmllllee");
  double accuracyPercent = tap.accuracy();
	ASSERT_EQ(accuracyPercent, 12);
}
