
#include "stdafx.h";
#include <stdlib.h>;
#include "./../src/Problem2.cpp";

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class Problem2Spec
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
		struct node_dll *newNode_DLL_spec(int key)
		{
			struct node_dll *temp = (struct node_dll *)malloc(sizeof(struct node_dll));
			temp->data = key;
			temp->next = NULL;
			temp->prev = NULL;
			return temp;
		}
		struct node_dll * make_dll_spec(int *arr, int len){
			struct node_dll *root = newNode_DLL_spec(arr[0]);
			struct node_dll *temp = root;
			for (int i = 1; i < len; i++){
				struct node_dll *cur = newNode_DLL_spec(arr[i]);
				temp->next = cur;
				cur->prev = temp;
				temp = temp->next;
			}
			return root;
		}
		struct node *newNode_spec(int key)
		{
			struct node *temp = (struct node *)malloc(sizeof(struct node));
			temp->data = key;
			temp->left = NULL;
			temp->right = NULL;
			return temp;
		}
		struct node * add_node_spec(struct node *root, int data){
			if (root == NULL) return newNode_spec(data);

			if (data < root->data)
				root->left = add_node_spec(root->left, data);
			else if (data > root->data)
				root->right = add_node_spec(root->right, data);

			return root;
		}
		struct node * make_bst_spec(int *arr, int len){
			struct node *root = NULL;
			for (int i = 0; i < len; i++){
				root = add_node_spec(root, arr[i]);
			}
			return root;
		}
		void delete_tree(struct node *root){
			if (root != NULL)
			{
				delete_tree(root->left);
				delete_tree(root->right);
				delete root;
				if (root->left != NULL)
					root->left = NULL;
				if (root->right != NULL)
					root->right = NULL;
				root = NULL;
			}
		}

		void test_Problem2_spec(int *arr,int *arr_bst,int len1,int len2,int ans){
			try{
				struct node_dll * head = make_dll_spec(arr, len1);
				struct node *root = make_bst_spec(arr_bst, len2);
				int check = is_identical(head, root);
				Assert::AreEqual(ans, check, L"Failed for Problem3", 1, 2);
				delete_tree(root);
			}
			catch (System::Exception ^e){
				Assert::AreEqual(1, 2, L"Exception maybe Nullpointer occured", 1, 2);
			}

		}
		[TestMethod, Timeout(1000)]
		void Sample1_Problem2()
		{
			try{
				int check = is_identical(NULL, NULL);
				Assert::AreEqual(-1, check, L"Failed sample 0 for NULL case in P1", 1, 2);
			}
			catch (System::Exception ^e){
				Assert::AreEqual(-1, 0, L"NULL pointer thrown", 1, 2);
			}
		};
		[TestMethod, Timeout(1000)]
		void Sample2_Problem2()
		{
			int arr[5] = { 1, 2, 3, 4, 5 };
			int bst_arr[5] = { 5, 3, 2, 1, 4 };
			int len1 = 5;
			int len2 = 5;
			int ans = 1;
			test_Problem2_spec(arr, bst_arr,len1,len2,ans);
			bst_arr[0] = 999;
			test_Problem2_spec(arr, bst_arr, len1, len2, 0);

		};


	};
}

