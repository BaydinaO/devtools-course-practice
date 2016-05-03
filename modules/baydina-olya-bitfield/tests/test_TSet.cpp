//Copyright 2016 Baydina Olya

#include "gtest.h"
#include "tbitfield.h"
#include "tset.h"

TEST(TSet, constructor){
    //Arrange
    TSet A(5);

    //Act & Assert
    EXPECT_EQ(5, A.GetMaxPower());
}

TEST(TSet, can_get_max_power_set){
    //Arrange
    const int size = 5;
    TSet set(size);

	//Act & Assert
    EXPECT_EQ(size, set.GetMaxPower());
}

TEST(TSet, can_insert_existing_element){
    //Arrange
    const int size = 5;
    const int k = 3;
    TSet set(size);

	//Act
    set.InsElem(k);
    set.InsElem(k);

    //Assert
    EXPECT_NE(set.IsMember(k), 0);
}

TEST(TSet, can_delete_non_existing_element){
    //Arrange
    const int size = 5, k = 3;
    TSet set(size);

	//Act
	set.DelElem(k);
    //Assert
    EXPECT_EQ(set.IsMember(k), 0);
}

TEST(TSet, compare_two_sets_of_non_equal_sizes){
    //Arrange
    const int size1 = 4, size2 = 6;
    TSet set1(size1), set2(size2);

    //Act & Assert
    EXPECT_EQ(1, set1 != set2);
}

TEST(TSet, compare_two_equal_sets){
    //Arrange
    const int size = 4;
    int result;
    TSet set1(size), set2(size);

	// Act
    set1.InsElem(1);
    set1.InsElem(3);
    set2.InsElem(1);
    set2.InsElem(3);
    result = (set1 == set2);

    //Assert
    EXPECT_EQ(set1, result);
}

TEST(TSet, can_do_several_operation_in_one_string){
    //Arrange
    int size = 4;
    TSet set1(size), set2(size), set3(size), setresult(size);

    //Act
    set1.InsElem(0);
    set2.InsElem(1);
    set3.InsElem(2);
    setresult.InsElem(0);
    setresult.InsElem(1); 
    setresult.InsElem(2);

    //Assert
    EXPECT_EQ(setresult, set1 + set2 + set3);
}
