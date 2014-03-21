/* 
|  FILE        :   LISTTOOL2.H
|
|  AUTHOR      :   Frode Haug, H?gskolen i Gj?vik
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

#if !defined(__LISTTOOL2_H)            //  Ensures that this file will be
#define __LISTTOOL2_H                  //    included only ONCE in each file.


			     //  ENUM:
enum listtype  { LIFO, FIFO, Sorted }; //  Allowed list-types.


			     //  CLASSES:
class Num_element;                     //  Predeclaration.
class Text_element;                    //  Predeclaration.

			     
class Element  {                       //  Base class 'Element'.
  private:
    char element_type;                 //  Type of element: 'B'(ase), 
				                       //    'N'(umeric) or 'T'(ext).
    friend class Num_element;          //  Only these two classes can 
    friend class Text_element;         //    manipulate 'element_type'.

  public:
    Element();                         //  Sets element type.
    virtual ~Element();                //  Virtual, empty destr.
    char get_type();                   //  Return element type.
    virtual int compare (Element* el);
    virtual void display();            //  Displayed only if function is NOT
};				                       //   redefined insided derived classes.


class Num_element: public Element  {   //  Base class for all numeric 
  protected:                           //    sorted elements.
    int number;                        //  ID-number.

  public:
    Num_element();                     //  Needs and reads the ID-number.
    Num_element(int no);               //  Created with an ID.
    virtual int compare(Element* el);  //  Compares own number with  el's.
};


class Text_element: public Element  {  //  Base class for all text/string
  protected:                           //    sorted elements.
    char* text;                        //  Pointer to ID-text/string.

  public:
    Text_element();                    //  Needs and reads the ID-name/text.
    Text_element(const char* t);       //  Created with an ID.
    ~Text_element();                   //  Deletes the text ID.
    virtual int compare(Element* el);  // Compares own name/text with el's.
};



class List  {                          //  The class 'List'.
  private:
    struct Node  {                     //  Internal struct 'node'.
      Element*  li_elem;               //  Element from the program that
				                       //    is stored inside THIS node.
      Node*     next;                  //  Nodes are linked together.
    };

    Node*     first;                   //  Pointer to first element/head.
    Node*     last;                    //  Pointer to tail. Only relevant
				                       //    for sorted lists.
    listtype  li_type;                 //  'LIFO', 'FIFO' or 'Sorted'.
    int       no_in_list;              //  Number of elements in the list.

    Node* find_position(Element* eptr); //  Internal function. Used by
					                    //    several other functions.
  public:
    List();                             //  Constructors.
    List(listtype li);
    ~List();                            //  Destructor.

	                                    //  15 functions available for the
					                    //    user/program. Some of them are
					                    //    overloaded:
					                    //  For different type of lists are
					                    //    the following functions relevant:
 					                    //  LIFO/FIFO   Num Sort   Text Sort
    int is_empty();                     //      X          X           X 
    int no_of_elements();               //      X          X           X
    bool add(Element* el);              //      X          X           X 
    Element* remove();                  //      X               
    Element* remove(int no);            //                 X
    Element* remove(const char* t);     //                             X
    Element* remove_no(int n);          //                 X           X
    bool destroy();                     //      X   
    bool destroy(int no);               //                 X
    bool destroy(const char* t);        //                             X
    bool in_list(int no);               //                 X
    bool in_list(const char* t);        //                             X
    bool display_element(int no);       //      X          X
    bool display_element(const char* t);//                             X
    void display_list();                //      X          X           X
}; 


#endif