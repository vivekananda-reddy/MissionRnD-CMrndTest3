
#include "stdafx.h";
#include <stdlib.h>;
#include "./../src/Problem4.cpp";

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class Problem4Spec
	{
	private:
		TestContext^ testContextInstance;
	public:
		property Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ TestContext
		{
			Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ get()
			{
				return testContextInstance;
			}
			System::Void set(Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ value)
			{
				testContextInstance = value;
			}
		};

#pragma region Additional test attributes
#pragma endregion 
		int search_node_p4(struct node *root,int key){
			if (root == NULL){
				return 0;
			}
			else if (root->data == key){
				return 1;
			}
			else{
				return search_node_p4(root->left, key) + search_node_p4(root->right, key);
			}
		}
		struct node *newNode_spec_p4(int key)
		{
			struct node *temp = (struct node *)malloc(sizeof(struct node));
			temp->data = key;
			temp->left = NULL;
			temp->right = NULL;
			return temp;
		}
		struct node * add_node_spec_p4(struct node *root, int data){
			if (root == NULL) return newNode_spec_p4(data);

			if (data <= root->data)
				root->left = add_node_spec_p4(root->left, data);
			else if (data > root->data)
				root->right = add_node_spec_p4(root->right, data);

			return root;
		}
		struct node * make_bst_spec_p4(int *arr, int len){
			struct node *root = NULL;
			for (int i = 0; i < len; i++){
				root = add_node_spec_p4(root, arr[i]);
			}
			return root;
		}
		void delete_tree_p4(struct node *root){
			if (root != NULL)
			{
				delete_tree_p4(root->left);
				delete_tree_p4(root->right);
				delete root;
				if (root->left != NULL)
					root->left = NULL;
				if (root->right != NULL)
					root->right = NULL;
				root = NULL;
			}
		}
		int total_count_p4(struct node *r1){
			if (r1 == NULL){
				return 0;
			}
			else{
				return 1 + total_count_p4(r1->left) + total_count_p4(r1->right);
			}
		}
		void test_Problem4_spec(int *a1, int *a2,int l1,int l2){
			struct node *r1 = make_bst_spec_p4(a1, l1);
			struct node *r2 = make_bst_spec_p4(a2, l2);
			merge_two_bst(r1,r2);
			//Checking all elements of BST1
			for (int i = 0; i < l1; i++){
				if (search_node_p4(r1, a1[i]) == 0){
					Assert::AreEqual(1, 2, L"Failed for P4", 1, 2);
					return;
				};
			}
			//checking all elements of BST2 in BST1
			for (int i = 0; i < l2; i++){
				if (search_node_p4(r1, a2[i]) == 0){
					Assert::AreEqual(1, 2, L"Failed for P4", 1, 2);
					return;
				};
			}
			
			int ans = l1 + l2;
			int actual = total_count_p4(r1);
			//Checking count
			Assert::AreEqual(ans,actual, L"Failed for P4 in Count", 1, 2);

			delete_tree_p4(r1);
			delete_tree_p4(r2);
		}

		//Sample Test Cases

		[TestMethod, Timeout(1000)]
		void Sample1_Problem4()
		{
			try{
				merge_two_bst(NULL, NULL);
			}
			catch (System::Exception ^e){
				Assert::AreEqual(-1, 0, L"NULL pointer thrown", 1, 2);
			}
		};
		[TestMethod, Timeout(1000)]
		void Sample2_Problem4()
		{
			int b1[] = { 20,5,30 };
			int b2[] = { 25,10,35 };
			int l1 = 3;
			int l2 = 3;
			test_Problem4_spec(b1,b2,l1,l2);
		};


	};

}

