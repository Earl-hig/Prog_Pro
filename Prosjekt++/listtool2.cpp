/* 
|  FILE        :   LISTTOOL2.CPP
|
|  AUTHOR      :   Frode Haug, H�gskolen i Gj�vik
|
|  IMPORT      :      None
|  EXPORT      :      None
|
|  DESCRIPTION :   Toolkit for handling of lists (LIFO, FIFO and
|                  NUMERIC/TEXT SORTED).  
|                  For more details:  see "LISTTOOL.DOC" (in norwegian).
|
|
+---------------------------------------------------------------------------+
|                      C H A N G E     H I S T O R Y
+----------+------------------------------------------+---------------------+
|   DATE   |  DESCRIPTION                             |  SIGN
+----------+------------------------------------------+---------------------+
|  020594  |  Initial.                                |  Frode Haug
|  270495  |  Virtual destructor in Element.          |  Frode Haug
|  170497  |  Extended if-test in remove(.....) (2x)  |  Frode Haug
|  040400  |  Some few small cosmetic corrections.    |  Frode Haug
|  220103  |  Updated for/to Standard C++.            |  Frode Haug
|  030204  |  Made this version for multifile projects|  Frode Haug
|          |                                          |
|          |                                          |
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*/       

			     //  INCLUDE:
#include <iostream>                    //  cout, cin
#include <cstring>                     //  strcpy, strlen, strcmp
#include "listtool2.h"                 //  Definition of classes.

using namespace std;

			       //  DEFINITION OF MEMBERFUNCTIONS:

                   //  Class "Element" member functions:
Element::Element()        {  element_type = 'B';    }   //  Sets element type.

Element::~Element()       {     }                       //  Virtual. Empty destr.

char Element::get_type()  {  return  element_type;  }   //  Return element type.

int Element::compare (Element* el)                      //  Virtual.
                          {  el = el; return 0; }       //  Dummy body.

void Element::display()            //  Virtual. Displayed only if function is
				                   //    NOT redefined insided derived classes.
	{  cout << "\nLISTTOOL - WARNING:\n\t'Display()' not "
		    << "implemented inside derived class.";  }


                   //  Class "Num_element" member functions:
Num_element::Num_element()                      //  Needs and reads the ID-number.
      {  cout << "\nID-number:  ";  cin >> number;  element_type = 'N';  }

Num_element::Num_element(int no)                //  Created with an ID.
      {  number = no;  element_type = 'N';  }

int Num_element::compare(Element* el)     //  Virtual. Compares own number with  el's.
      {  Num_element* nu_el = (Num_element*) el;
	     int diff = number - nu_el->number;
	     if (diff > 0)          return 1;
	     else if  (diff == 0)   return 0;
	     else                   return -1;  }

                   //  Class "Text_element" member functions:
Text_element::Text_element()                     //  Needs and reads the ID-name/text.
      {  char id[80];   cout << "\nID-text:  ";   cin.getline(id, 80);
	     text = new char[strlen(id)+1];  strcpy(text, id);
	     element_type = 'T';  }

Text_element::Text_element(const char* t)        //  Created with an ID.
      {  text = new char[strlen(t)+1]; strcpy(text, t); element_type = 'T'; }

Text_element::~Text_element()                    //  Deletes the text ID.
      {  delete [] text;   }

int Text_element::compare(Element* el)    // Virtual. Compares own name/text with el's.
      {  Text_element* te_el = (Text_element*) el;
	     return  strcmp(text, te_el->text);   }



                   //  Class "List" member functions:
				       //  Searches in a sorted list for the position for 
                       //    insertion of the element pointed to by 'eptr'.
				       //    RETURNS A POINTER TO THE NODE BEFORE THE 
                       //    RELEVANT POSITION.
List::Node* List::find_position(Element* eptr)  {
  Node* current = first;               //  Starts at the head.
				       //  As long as the inserted element
				       //    is greater than the next one,
				       //    and the tail is not reached:
  while (eptr->compare(current->next->li_elem) > 0  &&  current->next != last)
	current = current->next;       //  Update to next node.
  return current;                      //  Returns relevant pointer.
}


List::List()  {                        //  List created without the type.
  cout << "\nLISTTOOL - ERROR:\n\tYou MUST give 'LIFO', "
       << "'FIFO' or 'Sorted' when creating a 'List'.";   
}


List::List(listtype li)  {             //  Legal list is created.
				       //  Variables are initialized.
  li_type = li;   first = last = NULL;   no_in_list = 0; 
}


List::~List()  {                       //  Destructor to delete the list.
  Node* noptr;
  if (first)  {                        //  If something in the list.
     do  {
       noptr = first;                  //  'noptr' points to the node that
				       //     soon will be deleted.
       first = first->next;            //  Updates first to the next node.
       delete noptr->li_elem;          //  Deletes the content of the node.
       delete noptr;                   //  Deletes the node.
      } while (first);                 //  Proceed until all nodes are removed
     first = last = NULL;              //  Zeroes the pointers.
   }
}


int List::is_empty()  {                //  Returns if list is empty or not.
  return  (no_in_list == 0)  ?  1  :  0; 
}


int List::no_of_elements()  {          //  Returns current number of elements
  return  no_in_list;                  //    in the list.
}

				       
bool List::add(Element* eptr)  {       //  Add "eptr" into the list.
  Node*    new_node;                   //  Pointer to new created node.
  Node*    position;                   //  Pointer to the node BEFORE the
				       //    position for insertion.
  char litype;                         //  Relevant list type.
  bool added = false;                  //  Adding was successful or not.

  if (eptr)  {                         //  'eptr' REALLY points to something.
     switch (li_type)  {
     case LIFO:  new_node = new Node;       //  Creates new list-node.
		 new_node->li_elem = eptr;  //  Fills with data. 
		 new_node->next = first;    //  Adds to the beginning.
		 first = new_node;          //  Updates "first"
		 ++no_in_list;              //  Increments the number.
		 added = true;              //  Adding was successful.
		 break;

     case FIFO:  new_node = new Node;       //  Creates new list-node.
		 new_node->li_elem = eptr;  //  Fills with data.
		 new_node->next = NULL;     //  Initiates next-pointer.
		 if (last)                  //  If list NOT empty:
		    last->next = new_node;  //  Adds to the end. 
		 else                       //  List is empty:
		    first = new_node;       //  Adds as the first one.
		 last = new_node;           //  Updates "last".
		 ++no_in_list;              //  Increments the number.
		 added = true;              //  Adding was successful.
		 break;

     case Sorted: 
		 litype = eptr->get_type(); // Gets the element type.
		 if (litype == 'N'  ||  litype == 'T')  {  // Legal type:
		    if (first == NULL)  {   //  Empty list:
		       first = new Node;    //  Creates head
		       last = new Node;     //    and tail.
		       first->next = last;  //  Linking them together.
		       last->next = NULL;   //  Terminating the list.
		       if (litype == 'N')  {   //  Numeric list:
					    //  Fill head/tail:
			  first->li_elem = new Num_element(0);
			  last->li_elem = new Num_element(0);
		       } else {             //  Text/string list:
					    //  Fill head/tail:
			 first->li_elem = new Text_element("");
			 last->li_elem = new Text_element("");
		       }
		    }
					    //  Element of same type as those
					    //    those in the list:
		    if (litype ==  first->li_elem->get_type()) { 
		       new_node = new Node; //  Creates new list-node.
		       new_node->li_elem = eptr;  //  Fills with data.
					    //  Finds the position where
					    //    'eptr' will be inserted:
		       position = find_position(eptr);
					    //  Inserts 'eptr':
		       new_node->next = position->next;
		       position->next = new_node;
		       ++no_in_list;        //  Increments the number.
		       added = true;        //  Adding was succesful.
		    } else                  //  Element of another type
					    //    than those in the list:
		      cout << "\nLISTTOOL - WARNING:\n\tTrying "
			   << "to add element of wrong type "
			   << "into a sorted list.";
		 }  else                     //  Illegal element type:
		    cout << "\nLISTTOOL - ERROR:\n\tElements in "
			 << "Sorted lists MUST be derived\n\tfrom "
			 << "'Num_element' or 'Text_element'.";
		    break;

     default: cout << "\nLISTTOOL - ERROR:\n\tThis message (1) "
		   << "should never occur !";  break;
     }
  }  else                            //  Function was called with no element:
     cout << "\nLISTTOOL - WARNING:\n\t'Add()' called with no element.";
  return added;                        //  Returning with status of adding.
}

				       //  Returns (if possible) the FIRST 
Element* List::remove()  {             //    element in a LIFO-/FIFO-list.  
  Element* eptr = NULL;                //  Pointer to the removed element. 
  Node*  remove_node;                  //  Node that will be removed.

  if (li_type == LIFO  ||  li_type == FIFO)  {   // Legal list type:
     if (!is_empty())  {                //  Something in the list:
	eptr = first->li_elem;         //  Gets relevant element.
	remove_node = first;           //  Pointer to soon removed node.
	first = first->next;           //  Updates the first-pointer.
	if (first == NULL) last = NULL;  //  The list now are empty.
	   delete remove_node;         //  Deletes the first node.
	   --no_in_list;               //  Decrements the number.
     }
  } else                               //  Illegal use of the function:
    cout << "\nLISTTOOL - WARNING:\n\t'Remove()' shall "
	 << "only be called for LIFO or FIFO lists.";
  return eptr;                         //  Returns element or NULL.
}

				       //  Returns (if possible) element with
Element* List::remove(int no)  {       //   ID='no' in a numeric sorted list.
  Element* eptr = NULL;                //  Pointer to the removed element.
  Num_element* nuptr;                  //  Temporary element with equal ID.
  Node*  remove_node;                  //  Node that will be removed.
  Node*  position;                     //  Pointer to the node BEFORE the
				       //    possible relevant one. 
  if (first)  {                        //  At least head and tail:
				       //  Legal list type:
     if (li_type == Sorted  &&  first->li_elem->get_type() == 'N')  {      
	if (!is_empty())  {            //  Something in the list:
	   nuptr = new Num_element(no); //  Creates temporary element with
				       //     equal ID to the searhed one.
	   position = find_position(nuptr);  //  Finds the position BEFORE
					     //  the possible node/element.
				       // The next is the really searched one:
	   if (nuptr->compare(position->next->li_elem) == 0)  {
	      remove_node = position->next; //Pointer to the soon removed one.
	      eptr = remove_node->li_elem;  // Gets the element.
	      position->next = remove_node->next; // Skips node from the list.
	      delete remove_node;      // Deletes the node.
	      --no_in_list;            // Decrements the number in the list.
	   }
	   delete nuptr;               // Deletes the temporary element.
	}
     } else                            // Illegal use of the function:
       cout << "\nLISTTOOL - WARNING:\n\t'Remove(number)' shall "
	    << "only be called for NUMERIC SORTED lists.";
  }
  return eptr;                         //  Returns element or NULL.   
}

				       //  Returns (if possible) element with
Element* List::remove(const char* t) { //    ID='t' in a text sorted list.
  Element* eptr = NULL;                //  Pointer to the removed element.  
  Text_element* teptr;                 //  Temporary element with equal ID.  
  Node*  remove_node;                  //  Node that will be removed.
  Node*  position;                     //  Pointer to the node BEFORE the
				       //    possible relevant one.
  if (first)  {                        //  At least head and tail:
				       //  Legal list type:
     if (li_type == Sorted  &&  first->li_elem->get_type() == 'T')  {
	if (!is_empty())  {            //  Something in the list:
	   teptr = new Text_element(t);   // Creates temporary element with
				       //   equal ID to the searhed one.
	   position = find_position(teptr);   //  Finds the position BEFORE
					      //  the possible node/element.
				       // The next is the really searched one:
	   if (teptr->compare(position->next->li_elem) == 0)  {
	      remove_node = position->next; //Pointer to the soon removed one.
	      eptr = remove_node->li_elem;  // Gets the element.
	      position->next = remove_node->next; // Skips node from the list.
	      delete remove_node;      //  Deletes the node.
	      --no_in_list;            //  Decrements the number in the list.
	   }
	   delete teptr;               //  Deletes the temporary element.
	}
     } else                            //  Illegal use of the function:
       cout << "\nLISTTOOL - WARNING:\n\t'Remove(text)' shall "
	    << "only be called for TEXT/STRING SORTED lists.";
  }
  return eptr;                         //  Returns element or NULL.   
}

				       //  Returns (if possible) element no.
Element* List::remove_no(int n)  {     //    'n' in a num/text sorted list. 
  Element* eptr = NULL;                //  Pointer to the removed element.
  Node*  remove_node;                  //  Node that will be removed.
  Node*  position;                     //  Pointer to the node BEFORE the
				       //    possible relevant one.
  if (li_type == Sorted)  {            //  Legal list type:
     if (!is_empty())  {               //  Something in the list:
	if (no_in_list >= n)  {        //  Number 'n' exsists:
	   position = first;           //  Start search at the head.
				       //  Loop to the node BEFORE. 
	   for (int i = 1;  i < n;  i++, position = position->next)   
	       ;                       //  NOTE: Empty body !
	   remove_node = position->next;   // Pointer to the soon removed one.
	   eptr = remove_node->li_elem;    // Gets the element.
	   position->next = remove_node->next; //Skips the node from the list.
	   delete remove_node;         //  Deletes the node.
	   --no_in_list;               //  Decrements the number in the list.
	}
     }
  } else                               //  Illegal use of the function:
    cout << "\nLISTTOOL - WARNING:\n\t'Remove_no(n)' "
	 << "shall only be called for SORTED lists.";
  return eptr;                         //  Returns element or NULL.
}

				       
				       //  Destroys (if possible) the FIRST 
bool List::destroy()  {                //    element in a LIFO-/FIFO-list. 
  Element* eptr;                       //  Pointer to the destroyed element.
  bool destroyed = false;              //  Destroying was successful or not.

  if (li_type == LIFO  ||  li_type == FIFO)  {   //  Legal list type:
     if (!is_empty())  {               //  Something in the list:
	eptr = remove();               //  Gets first element.
	delete eptr;                   //  Delete element.
	destroyed = true;              //  Destroying was successful.
     }
  } else                               //  Illegal use of function.
    cout << "\nLISTTOOL - WARNING:\n\t'Destroy()' shall "
	 << "only be called for LIFO or FIFO lists.";
  return destroyed;                    //  Return with status of destroying.
}

				       //  Destroys (if possible) the element
				       //    with ID='no' from a numeric
bool List::destroy(int no)  {          //    sorted list.
  Element* eptr;                       //  Pointer to the destroyed element.
  bool destroyed = false;              //  Destroying was successful or not.

  if (first)  {                        //  At least head and tail:
				       //  Legal list type:
     if (li_type == Sorted  &&  first->li_elem->get_type() == 'N')  {
	if (!is_empty())  {            //  Something in the list:
	   eptr = remove(no);          //  Get (if possible) relevant element.
	   if (eptr)  {                //  Element found:
	      delete eptr;             //  Delete element. 
	      destroyed = true;        //  Destroying was successful.
	   }
	}
     } else                            //  Illegal use of function.
       cout << "\nLISTTOOL - WARNING:\n\t'Destroy(no)' shall "
	    << "only be called for NUMERIC SORTED lists.";
  }
  return destroyed;                    //  Return with status of destroying.
}
				       //  Destroys (if possible) the element
				       //    with ID='t' from a text/string
bool List::destroy(const char* t)  {   //    sorted list.
  Element* eptr;                       //  Pointer to the destroyed element.
  bool destroyed = false;              //  Destroying was successful or not.

  if (first)  {                        //  At least head and tail:
				       //  Legal list type:
     if (li_type == Sorted  &&  first->li_elem->get_type() == 'T')  {
	if (!is_empty())  {            //  Something in the list:
	   eptr = remove(t);           //  Get (if possible) relevant element.
	   if (eptr)  {                //  Element found:
	      delete eptr;             //  Delete element. 
	      destroyed = true;        //  Destroying was successful.
	   }
	}
     } else                            //  Illegal use of function.
       cout << "\nLISTTOOL - WARNING:\n\t'Destroy(text)' shall "
	    << "only be called for TEXT/STRING SORTED lists.";
  }
  return destroyed;                    //  Return with status of destroying.
}

				       //  Looks for element with ID='no'
bool List::in_list(int no)  {          //    in a numeric sorted list.
  Num_element* neptr;                  //  Temporary element with equal ID.
  Node* position;                 //  Pointer to node BEFORE the possible one.
  bool is_there = false;                //  Element found or not. 

  if (first)  {                        //  At least head and tail:
				       //  Legal list type: 
     if (li_type == Sorted  &&  first->li_elem->get_type() == 'N')  {
	if (!is_empty())  {            //  Something in the list:
	   neptr = new Num_element(no);   //  Creates temporary element with
					  //    equal ID to the searhed one.
	   position = find_position(neptr);   //  Finds the position BEFORE
					      //  the possible node/element.
					 // The next is the really searched one:
	   if (neptr->compare(position->next->li_elem) == 0)
	      is_there = true;            //  Searching was successful. 
	   delete neptr;                  //  Deletes the temporary element.
	}
     } else                            //  Illegal use of the function. 
       cout << "\nLISTTOOL - WARNING:\n\t'In_list(no)' shall "
	    << "only be called for NUMERIC SORTED lists.";
  }
  return is_there;                     //  Return the status of the search.
}


				       //  Looks for element with ID='t'
bool List::in_list(const char* t)  {   //    in a text/string sorted list.
  Text_element* teptr;                 //  Temporary element with equal ID.
  Node* position;                 //  Pointer to node BEFORE the possible one.
  bool is_there = false;               //  Element found or not. 

  if (first)  {                        //  At least head and tail:
				       //  Legal list type: 
     if (li_type == Sorted  &&  first->li_elem->get_type() == 'T')  {
	if (!is_empty())  {                  //  Something in the list:
	   teptr = new Text_element(t);   //  Creates temporary element with
					  //    equal ID to the searhed one.
	   position = find_position(teptr);   //  Finds the position BEFORE
					      //  the possible node/element.
					 // The next is the really searched one:
	   if (teptr->compare(position->next->li_elem) == 0)
	      is_there = true;            //  Searching was successful. 
	   delete teptr;                  //  Deletes the temporary element.
	}
     } else                            //  Illegal use of the function. 
       cout << "\nLISTTOOL - WARNING:\n\t'In_list(text)' shall "
	    << "only be called for TEXT/STRING SORTED lists.";
  }
  return is_there;                     //  Return the status of the search.
}

				       //  Displays element no.'no' in a LIFO-
				       //    or FIFO-list, OR displays element
				       //    with ID='no' in a numeric sorted
bool List::display_element(int no)   { //    list.
  Num_element* nuptr;                  //  Temporary element with equal ID.
  Node*  current;                      //  Pointer to relevant node.
  bool displayed = false;              //  Element displayed or not.  

  if (!is_empty())  {                  //  Something in the list.
     if (li_type == LIFO  ||  li_type == FIFO)  {    //  Case: LIFO/FIFO:
	if (no_in_list >= no)  {       //  Element no.'no' IS there:
	   current = first;            //  Start at the first node.
				       //  Find relevant node:
	   for (int i = 1;  i < no;  i++, current = current->next)
	       ;                       //  NOTE:  Empty body !
	   current->li_elem->display();   //  Display the element. 
	   displayed = true;           //  Displayment was successful.
	}                              //  Case:  NUMERIC SORTED list:
     } else if (li_type == Sorted  &&  first->li_elem->get_type() == 'N')  {
	   nuptr = new Num_element(no); // Creates temporary element with
					//   equal ID to the searhed one.
	   current = find_position(nuptr); // Finds the position BEFORE
					   //   the possible node/element.
	   current = current->next;    //  Update to relevant one.
				       // The node is the really searched one:
	   if (nuptr->compare(current->li_elem) == 0)  {
	      current->li_elem->display();    //  Display the element.
	      displayed = true;        //  Displayment was successful.
	   }
	   delete nuptr;               //  Delete temporary element.
     } else                            //  Illegal use of the function:
       cout << "\nLISTTOOL - WARNING:\n\t'Display_element(no)' shall only "
	    << "be called for\n\t LIFO-, FIFO- and NUMERIC SORTED lists.";
  }
  return displayed;                    //  Return status of the displayment.
}

				       //  Displays element with ID='t' in
bool List::display_element(const char* t) { //  a TEXT/STRING SORTED list.
  Text_element* teptr;                 //  Temporary element with equal ID.
  Node*  current;                      //  Pointer to relevant node.
  bool displayed = false;              //  Element displayed or not.  

  if (first)  {                        //  At least head and tail:
				       //  Legal list type:
     if (li_type == Sorted  &&  first->li_elem->get_type() == 'T')  {
	if (!is_empty())  {            //  Something in the list:
	   teptr = new Text_element(t); // Creates temporary element with
				       //    equal ID to the searhed one.
	   current = find_position(teptr);    //  Finds the position BEFORE
				       //  the possible node/element.
	   current = current->next;    //  Update to relevant one.
				       // The node is the really searched one:
	   if (teptr->compare(current->li_elem) == 0)  {
	      current->li_elem->display();    //  Display the element.
	      displayed = true;        //  Displayment was successful.
	   }
	   delete teptr;               //  Delete temporary element.
	}
     } else                            //  Illegal use of the function:
       cout << "\nLISTTOOL - WARNING:\n\t'Display_element(text)' "
	    << "shall only be called for TEXT SORTED lists.";
  }
  return displayed;                    //  Return status of the displayment.
}

				       //  Displays the WHOLE content of a
void List::display_list()  {           //    arbitrary list.
  Node* current = first;               //  Pointer to current node.

  if (!is_empty())  {                  //  Something in the list:
     if (li_type == Sorted)            //  If sorted:
	current = current->next;       //    skip the head.
				       //  For all nodes/elements:
     for (int i = 1;  i <= no_in_list;  i++, current = current->next)
	 current->li_elem->display();  //  Display element.
  }                                    //  Display number of elements:
//  cout << "\n\tNumber of elements in the list:  " << no_in_list;
}