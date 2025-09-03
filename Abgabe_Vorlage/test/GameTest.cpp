#include <gtest/gtest.h>
#include <gmock/gmock.h>

TEST(GameTest, example) { 
  // Expect equality.
  EXPECT_EQ(3 * 4, 12);
}

/*Da die Logik intern in den Control und Model Klassen bereits getestet wird (input, draw & update ) 
oder es sich um Methoden mit sprites handelt, die wir wie in collisions nicht testen können, ist in dieser Klasse kein Test Bedarf*/