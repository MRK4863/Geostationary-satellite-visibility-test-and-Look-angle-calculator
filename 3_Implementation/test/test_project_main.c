#include "unity.h"

/* Modify these two lines according to the project */
#include <calc_operations.h>
#define PROJECT_NAME "Calculator"

/* Prototypes for all the test functions */
void test_deg_to_rad(void);
void test_rad_to_deg(void);
void test_elevation_calc(void);
void test_azimuth_calc(void);
void test_visibility_test(void);

/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}

/* Start of the application test */
int main()
{
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();

/* Run Test functions */
  RUN_TEST(test_deg_to_rad);
  RUN_TEST(test_rad_to_deg);
  RUN_TEST(test_elevation_calc);
  RUN_TEST(test_azimuth_calc);
  RUN_TEST(test_visibility_test);

  /* Close the Unity Test Framework */
  return UNITY_END();
}

/* Write all the test functions */ 
void test_deg_to_rad(void)
{
    TEST_ASSERT_EQUAL(3.142, deg_to_rad(180));
  
  /* Dummy fail*/
    TEST_ASSERT_EQUAL(1.571, deg_to_rad(90));
}
void test_rad_to_deg(void)
{
    TEST_ASSERT_EQUAL(180.0, rad_to_deg(3.142));
  
  /* Dummy fail*/
    TEST_ASSERT_EQUAL(90.0, rad_to_deg(1.571));
}

void test_elevation_calc(void)
{
    TEST_ASSERT_EQUAL(15.612381, elevation_calc(39994.546875, 42160, 66));
}

void test_azimuth_calc(void)
{
    TEST_ASSERT_EQUAL(90.011665, azimuth_calc(66,0,52,'N'));
}

void test_visibility_test(void)
{
    TEST_ASSERT_EQUAL(1, visibility_test(1.15192));
}
