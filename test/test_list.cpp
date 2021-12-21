#include "list.h"
#include <gtest.h>

TEST(Node, can_create_node)
{
  ASSERT_NO_THROW(Node a);
}

TEST(List, can_create_list)
{
  ASSERT_NO_THROW(List l);
}

TEST(List, new_list_is_empty)
{
	List l;
	EXPECT_EQ(true, l.isEmpty());
}

TEST(List, can_add_elem_to_empty_list)
{
	List l;
	l.InsertToHead(4);
}

TEST(List, can_add_elem_to_notempty_list)
{
	List l;
	l.InsertToHead(4);
	l.InsertToHead(5);
	EXPECT_EQ(5, l.ViewHead());
}

TEST(List, can_add_to_tail_1)
{
	List l;
	l.InsertToTail(4);
	EXPECT_EQ(4, l.ViewHead());
}

TEST(List, can_add_to_tail_2)
{
	List l;
	l.InsertToTail(4);
	l.InsertToTail(5);
	l.InsertToTail(6);
	EXPECT_EQ(4, l.ViewHead());
	// как проверить последний?
}

TEST(List, can_clean_empty_list)
{
	List l;
	ASSERT_NO_THROW(l.Clean());
}

TEST(List, can_clean2)
{
	List l;
	l.InsertToTail(4);
	l.Clean();
	EXPECT_EQ(true, l.isEmpty());
}

TEST(List, can_clean3)
{
	List l;
	l.InsertToTail(4);
	l.InsertToTail(5);
	l.InsertToTail(6);
	l.Clean();
	EXPECT_EQ(true, l.isEmpty());
}

TEST(List, iterator1)
{
	List l;
	l.InsertToHead(4);
	ASSERT_NO_THROW(myiterator h = l.begin());
}

TEST(List, iterator2)
{
	List l;
	l.InsertToHead(4);
	myiterator h = l.begin();
	EXPECT_EQ(4, *h);
}

TEST(List, iterator3)
{
	List l;
	l.InsertToHead(4);
	l.InsertToTail(5);
	myiterator h = l.begin();
	++h;
	EXPECT_EQ(5, *h);
}


TEST(List, can_delete1)
{
	List l;
	l.InsertToTail(4);
	l.InsertToTail(5);
	l.InsertToTail(6);

	l.Delete(5);

	myiterator it = l.begin();
	++it;
	EXPECT_EQ(6, *it);
}

TEST(List, can_delete2)
{
	List l;
	l.InsertToTail(4);
	l.InsertToTail(5);
	l.InsertToTail(6);

	l.Delete(4);

	myiterator it = l.begin();
	EXPECT_EQ(5, *it);
}

TEST(List, can_delete3)
{
	List l;
	l.InsertToTail(4);
	l.InsertToTail(5);
	l.InsertToTail(6);

	ASSERT_NO_THROW(l.Delete(7));
}

/*
class EmptyList : public testing::Test
{
protected:
  List l;
public:
  EmptyList() {};
  ~EmptyList() {};
};

TEST_F(EmptyList, new_list_is_empty)
{
  EXPECT_EQ(NULL, l.GetHead());
}

TEST_F(EmptyList, size_of_new_list_is_zero)
{
  EXPECT_EQ(0, l.GetSize());
}

TEST_F(EmptyList, can_copy_empty_list)
{
  ASSERT_NO_THROW(List l2(l));
}

TEST_F(EmptyList, empty_list_copy_is_correct)
{
  List l2(l);
  EXPECT_EQ(NULL, l2.GetHead());
}

TEST_F(EmptyList, size_of_empty_list_copy_is_correct)
{
  List l2(l);
  EXPECT_EQ(0, l2.GetSize());
}

TEST_F(EmptyList, two_empty_lists_are_eq)
{
  List l2;
  EXPECT_EQ(true, l == l2);
}

TEST_F(EmptyList, can_assign_two_empty_lists)
{
  List l2;
  ASSERT_NO_THROW(l = l2); 
}

TEST_F(EmptyList, can_assign_empty_list_to_itself)
{
  ASSERT_NO_THROW(l = l); 
}

TEST_F(EmptyList, assign_two_empty_lists_is_correct)
{
  List l2;
  l = l2;
  EXPECT_EQ(NULL, l.GetHead());
}

TEST_F(EmptyList, can_insert_to_head_for_empty_list)
{
  l.InsertToHead(5);
  EXPECT_EQ(5, l.GetHead()->data);
  EXPECT_EQ(NULL, l.GetHead()->next);
}

TEST_F(EmptyList, can_insert_to_tail_for_empty_list)
{
  l.InsertToTail(5);
  EXPECT_EQ(5, l.GetHead()->data);
  EXPECT_EQ(NULL, l.GetHead()->next);
}

TEST_F(EmptyList, cant_insert_after_for_empty_list)
{
  Node* p = l.GetHead();
  ASSERT_ANY_THROW(l.InsertAfter(p, 5));
}

TEST_F(EmptyList, can_delete_from_empty_list)
{
  ASSERT_NO_THROW(l.Delete(5));
}

TEST_F(EmptyList, delete_from_empty_list_is_correct)
{
  l.Delete(5);
  EXPECT_EQ(NULL, l.GetHead());
}

TEST_F(EmptyList, can_search_for_empty_list)
{
  ASSERT_NO_THROW(l.Search(5));
}

TEST_F(EmptyList, search_for_empty_list_is_correct)
{
  Node* p = l.Search(5);
  EXPECT_EQ(NULL, p);
}

TEST_F(EmptyList, can_clean_empty_list)
{
  ASSERT_NO_THROW(l.Clean());
}

TEST_F(EmptyList, clean_empty_list_is_correct)
{
  l.Clean();
  EXPECT_EQ(NULL, l.GetHead());
}

TEST_F(EmptyList, can_inverse_empty_list)
{
  ASSERT_NO_THROW(l.Inverse());
}

TEST_F(EmptyList, empty_list_is_empty_after_inverse)
{
  l.Inverse();
  List l2;
  EXPECT_EQ(l2, l);
}

TEST_F(EmptyList, can_merge_two_empty_lists)
{
  List l2;
  ASSERT_NO_THROW(l.Merge(l2));
}

TEST_F(EmptyList, merge_two_empty_lists_is_correct)
{
  List l2;
  List l3 = l.Merge(l2);
  EXPECT_EQ(l2, l3);
}

TEST_F(EmptyList, can_merge_after_ptr_for_two_empty_lists)
{
  List l2;
  ASSERT_NO_THROW(l.Merge(l.GetHead(), l2)); // ? тут неоднозначно. Ѕудем считать, что исключени¤ нет, список не мен¤етс¤
}

TEST_F(EmptyList, merge_after_ptr_for_two_empty_lists_is_correct)
{
  List l2;
  List l3 = l.Merge(l.GetHead(), l2); 
  EXPECT_EQ(l2, l3);
}

//------------------------------------------------------------------------------------------

class ThreeNodesList : public testing::Test
{
protected:
  List l;
public:
  ThreeNodesList()
  {
    l.InsertToTail(1);
    l.InsertToTail(2);
    l.InsertToTail(3);
  }
  ~ThreeNodesList() {};
};

TEST_F(ThreeNodesList, three_nodes_list_is_correct)
{
  EXPECT_EQ(1, l.GetHead()->data);
  EXPECT_EQ(2, l.GetHead()->next->data);
  EXPECT_EQ(3, l.GetHead()->next->next->data);
  EXPECT_EQ(NULL, l.GetHead()->next->next->next);
}

TEST_F(ThreeNodesList, size_of_new_list_is_three)
{
  EXPECT_EQ(3, l.GetSize());
}

TEST_F(ThreeNodesList, can_copy_not_empty_list)
{
  ASSERT_NO_THROW(List l2(l));
}

TEST_F(ThreeNodesList, copy_of_not_empty_list_is_correct)
{
  List l2(l);
  // так написано, т.к. предполагаем, что == еще не реализовано или не работает
  EXPECT_EQ(1, l2.GetHead()->data);
  EXPECT_EQ(2, l2.GetHead()->next->data);
  EXPECT_EQ(3, l2.GetHead()->next->next->data);
  EXPECT_EQ(NULL, l2.GetHead()->next->next->next);
}

TEST_F(ThreeNodesList, copied_list_has_its_own_memory)
{
  List l2(l);
  EXPECT_NE(l.GetHead(), l2.GetHead());
  EXPECT_NE(l.GetHead()->next, l2.GetHead()->next);
  EXPECT_NE(l.GetHead()->next->next, l2.GetHead()->next->next);
}

TEST_F(ThreeNodesList, not_empty_list_is_correct_after_assigning_to_itself)
{
  List l2(l);
  l = l;
  EXPECT_EQ(l2, l);
}

TEST_F(ThreeNodesList, size_of_not_empty_list_copy_is_correct)
{
  List l2(l);
  EXPECT_EQ(3, l2.GetSize());
}

TEST_F(ThreeNodesList, can_insert_to_head_for_not_empty_list)
{
  l.InsertToHead(5);
  EXPECT_EQ(5, l.GetHead()->data);
  EXPECT_EQ(1, l.GetHead()->next->data);
}

TEST_F(ThreeNodesList, can_insert_to_tail_for_not_empty_list)
{
  l.InsertToTail(5);
  EXPECT_EQ(5, l.GetHead()->next->next->next->data);
  EXPECT_EQ(NULL, l.GetHead()->next->next->next->next);
}

TEST_F(ThreeNodesList, can_insert_after_null_ptr_for_not_empty_list)
{
  ASSERT_NO_THROW(l.InsertAfter(NULL, 5));
}

TEST_F(ThreeNodesList, insert_after_null_ptr_for_not_empty_list_is_correct)
{
  List l2(l);
  l.InsertAfter(NULL, 5);
  EXPECT_EQ(l2, l);
}

TEST_F(ThreeNodesList, can_insert_after_ptr_for_not_empty_list)
{
  Node* p = l.GetHead()->next;
  ASSERT_NO_THROW(l.InsertAfter(p, 5));
}

TEST_F(ThreeNodesList, insert_after_ptr_for_not_empty_list_is_correct)
{
  Node* p = l.GetHead()->next;
  l.InsertAfter(p, 5);

  EXPECT_EQ(2, l.GetHead()->next->data);
  EXPECT_EQ(5, l.GetHead()->next->next->data);
  EXPECT_EQ(3, l.GetHead()->next->next->next->data);
  EXPECT_EQ(NULL, l.GetHead()->next->next->next->next);
}

TEST_F(ThreeNodesList, can_delete_head_from_not_empty_list)
{
  ASSERT_NO_THROW(l.Delete(1));
}

TEST_F(ThreeNodesList, can_delete_head_from_not_empty_list2)
{
  l.Delete(1);
  EXPECT_EQ(2, l.GetHead()->data);
}

TEST_F(ThreeNodesList, can_delete_middle_from_not_empty_list)
{
  l.Delete(2);
  EXPECT_EQ(1, l.GetHead()->data);
  EXPECT_EQ(3, l.GetHead()->next->data);
}

TEST_F(ThreeNodesList, can_delete_tail_from_not_empty_list)
{
  l.Delete(3);
  EXPECT_EQ(1, l.GetHead()->data);
  EXPECT_EQ(2, l.GetHead()->next->data);
  EXPECT_EQ(NULL, l.GetHead()->next->next);
}

TEST_F(ThreeNodesList, can_delete_not_a_member_from_not_empty_list)
{
  ASSERT_NO_THROW(l.Delete(5));
}

TEST_F(ThreeNodesList, can_delete_not_a_member_from_not_empty_list2)
{
  l.Delete(5);
  EXPECT_EQ(1, l.GetHead()->data);
  EXPECT_EQ(2, l.GetHead()->next->data);
  EXPECT_EQ(3, l.GetHead()->next->next->data);
  EXPECT_EQ(NULL, l.GetHead()->next->next->next);
}


TEST_F(ThreeNodesList, can_search_for_not_empty_list)
{
  ASSERT_NO_THROW(l.Search(3));
}

TEST_F(ThreeNodesList, search_for_not_empty_list_is_correct)
{
  Node* p = l.Search(3);
  Node* ptrue = l.GetHead()->next->next;
  EXPECT_EQ(ptrue, p);
}

TEST_F(ThreeNodesList, can_search_not_a_member_for_not_empty_list)
{
  ASSERT_NO_THROW(l.Search(5));
}

TEST_F(ThreeNodesList, search_not_a_member_for_not_empty_list_is_correct)
{
  Node* p = l.Search(5);
  EXPECT_EQ(NULL, p);
}

TEST_F(ThreeNodesList, can_clean_not_empty_list)
{
  ASSERT_NO_THROW(l.Clean());
}

TEST_F(ThreeNodesList, clean_not_empty_list_is_correct)
{
  l.Clean();
  EXPECT_EQ(NULL, l.GetHead());
}

TEST_F(ThreeNodesList, size_of_not_empty_list_after_clean_is_correct)
{
  l.Clean();
  EXPECT_EQ(0, l.GetSize());
}

TEST_F(ThreeNodesList, can_inverse_not_empty_list)
{
  ASSERT_NO_THROW(l.Inverse());
}

TEST_F(ThreeNodesList, not_empty_list_is_correct_after_inverse)
{
  l.Inverse();
  EXPECT_EQ(3, l.GetHead()->data);
  EXPECT_EQ(2, l.GetHead()->next->data);
  EXPECT_EQ(1, l.GetHead()->next->next->data);
  EXPECT_EQ(NULL, l.GetHead()->next->next->next);
}

TEST_F(ThreeNodesList, can_assign_not_empty_list_to_itself)
{
  ASSERT_NO_THROW(l = l); 
}


TEST_F(ThreeNodesList, can_assign_two_not_empty_lists)
{
  List l2;
  l2.InsertToTail(22);
  l2.InsertToTail(33);
  ASSERT_NO_THROW(l = l2); 
}

TEST_F(ThreeNodesList, list_after_assign_has_its_own_memory)
{
  List l2;
  l2.InsertToTail(22);
  l2.InsertToTail(33);
  l = l2;
  EXPECT_NE(l.GetHead(), l2.GetHead());
  EXPECT_NE(l.GetHead()->next, l2.GetHead()->next);
}

TEST_F(ThreeNodesList, can_assign_two_not_empty_lists_of_eq_size)
{
  List l2;
  l2.InsertToTail(11);
  l2.InsertToTail(22);
  l2.InsertToTail(33);
  l = l2;
  EXPECT_EQ(11, l.GetHead()->data);
  EXPECT_EQ(22, l.GetHead()->next->data);
  EXPECT_EQ(33, l.GetHead()->next->next->data);
  EXPECT_EQ(NULL, l.GetHead()->next->next->next);
}

TEST_F(ThreeNodesList, compare_two_eq_lists_is_correct)
{
  List l2(l);
  EXPECT_EQ(true, l == l2);
}


class TwoListsTest : public testing::Test
{
protected:
  List l;
  List l2;
  List z;

public:
  TwoListsTest()
  {
    l.InsertToTail(1);
    l.InsertToTail(2);
    l.InsertToTail(3);
    l2.InsertToTail(11);
    l2.InsertToTail(22);
  }

  ~TwoListsTest() {}
};

TEST_F(TwoListsTest, can_assign_two_not_empty_lists_of_not_eq_size)
{
  ASSERT_NO_THROW(l = l2);
}

TEST_F(TwoListsTest, assign_two_not_empty_lists_of_not_eq_size_is_correct)
{
  l = l2;
  EXPECT_EQ(11, l.GetHead()->data);
  EXPECT_EQ(22, l.GetHead()->next->data);
  EXPECT_EQ(NULL, l.GetHead()->next->next);
}

TEST_F(TwoListsTest, assign_list_to_empty_is_correct)
{
  l = z;
  EXPECT_EQ(NULL, l.GetHead());
}

TEST_F(TwoListsTest, assign_empty_list_to_not_empty_is_correct)
{
  z = l;
  EXPECT_EQ(l, z);
}

TEST_F(TwoListsTest, can_compare_two_not_empty_lists)
{
  ASSERT_NO_THROW(l == l2); 
}

TEST_F(TwoListsTest, compare_two_not_eq_lists_of_eq_size)
{
  l2.InsertToHead(3);
  EXPECT_EQ(false, l == l2);
}

TEST_F(TwoListsTest, compare_two_not_eq_lists_with_bigger_list_left)
{
  EXPECT_EQ(false, l == l2);
}

TEST_F(TwoListsTest, compare_two_not_eq_lists_with_bigger_list_right)
{
  EXPECT_EQ(false, l2 == l);
}

TEST_F(TwoListsTest, compare_list_with_empty_list_left)
{
  EXPECT_EQ(false, z == l2);
}

TEST_F(TwoListsTest, compare_list_with_empty_list_right)
{
  EXPECT_EQ(false, l2 == z);
}

TEST_F(TwoListsTest, can_merge_two_not_empty_lists)
{
  ASSERT_NO_THROW(l.Merge(l2));
}

TEST_F(TwoListsTest, merge_two_not_empty_lists_is_correct)
{
  List l3 = l.Merge(l2);
  List res;
  res.InsertToTail(1);
  res.InsertToTail(2);  
  res.InsertToTail(3);
  res.InsertToTail(11);
  res.InsertToTail(22);

  EXPECT_EQ(res, l3);
}

TEST_F(TwoListsTest, merge_not_empty_and_empty_list_right)
{
  List l3 = l.Merge(z);
  EXPECT_EQ(l, l3);
}

TEST_F(TwoListsTest, merge_not_empty_and_empty_list_left)
{
  List l3 = z.Merge(l);
  EXPECT_EQ(l, l3);
}

TEST_F(TwoListsTest, can_merge_after_ptr_two_not_empty_lists)
{
    ASSERT_NO_THROW(l.Merge(l.GetHead()->next, l2));
}

TEST_F(TwoListsTest, merge_after_ptr_two_not_empty_lists_is_correct)
{
    List l3 = l.Merge(l.GetHead()->next, l2);
    List res;
    res.InsertToTail(1);
    res.InsertToTail(2);  
    res.InsertToTail(11);
    res.InsertToTail(22);
    res.InsertToTail(3);
    EXPECT_EQ(res, l3);
}

TEST_F(TwoListsTest, merge_after_ptr_for_not_empty_list_and_empty_list_is_correct)
{
    List l3 = l.Merge(l.GetHead()->next, z);
    EXPECT_EQ(l, l3);
}

TEST_F(TwoListsTest, can_merge_after_null_ptr_for_not_empty_list)
{
    ASSERT_NO_THROW(l.Merge(NULL, l2));
}

TEST_F(TwoListsTest, merge_after_null_ptr_for_not_empty_list_is_correct)
{
    List l3 = l.Merge(NULL, l2);
    EXPECT_EQ(l, l3);
}


TEST(List, inverse_of_one_node_list_is_correct)
{
  List l;
  l.InsertToTail(5);
  l.Inverse();
  EXPECT_EQ(5, l.GetHead()->data);
  EXPECT_EQ(NULL, l.GetHead()->next);
}


*/