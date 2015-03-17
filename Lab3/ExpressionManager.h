/*
 * File:   ExpressionManager.h
 * Author: misaie
 *
 * Created on May 15, 2014, 10:55 AM
 */

#ifndef EXPRESSIONMANAGER_H
#define	EXPRESSIONMANAGER_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stack>
#include <iostream>

#include <stdlib.h>
#include "ExpressionManagerInterface.h"


    using namespace std;

    class ExpressionManager : public ExpressionManagerInterface
    {
    public:
ExpressionManager()
{


}
~ExpressionManager()
{

}

/*Checks whether an expression is balanced on its parentheses.
 * The given expression will have a space between every number or operator,
 * return true if expression is balance, return false otherwise*/
virtual bool isBalanced(string expression)
{
    string noparenthesis;

    for (int i = 0 ; i < expression.length() ; i++)
    {
        if (noparenthesis.length() == 0)
        {
        if ( expression[i] == '(') { noparenthesis = "(" ;}
        if ( expression[i] == ')') { noparenthesis = ")" ;}
        if ( expression[i] == '[') { noparenthesis = "[" ;}
        if ( expression[i] == ']') { noparenthesis = "]" ;}
        if ( expression[i] == '{') { noparenthesis = "{" ;}
        if ( expression[i] == '}') { noparenthesis = "}" ;}
        }else
        {
        if ( expression[i] == '(') { noparenthesis = noparenthesis + "(" ;}
        if ( expression[i] == ')') { noparenthesis = noparenthesis + ")" ;}
        if ( expression[i] == '[') { noparenthesis = noparenthesis + "[" ;}
        if ( expression[i] == ']') { noparenthesis = noparenthesis + "]" ;}
        if ( expression[i] == '{') { noparenthesis = noparenthesis + "{" ;}
        if ( expression[i] == '}') { noparenthesis = noparenthesis + "}" ;}
        }
    }

    if ( noparenthesis.size() == 0) { return true; }



    stack<char> parenthesis;

    //cout << " expression is " << expression << endl;
    //cout << " noparenthesis is " << noparenthesis << endl;
    //cout << " it length is " << noparenthesis.length() << endl;

    int forloop = 0;

    for(int i = 0 ; i < noparenthesis.length() ; i++)
    {

        //cout << " inside for" << endl;
        //cout << " expression[i] is " << noparenthesis[i] << endl;

        if (noparenthesis[i] == '(' || noparenthesis[i] == '{' || noparenthesis[i] == '[' )
        {
            parenthesis.push(noparenthesis[i]);

            //cout << " char is " << noparenthesis[i] << endl;
            //cout << " entering " << parenthesis.top() << endl;

        }else


        if ( parenthesis.empty() == false )
        {
        if (noparenthesis[i] == ')' && parenthesis.top() == '(' )
        {

            //cout << " char is " << noparenthesis[i] << endl;
            //cout << " erasing " << parenthesis.top() << endl;

            parenthesis.pop();
        }else


        if ( noparenthesis[i] == '}' && parenthesis.top() == '{' )
        {

            //cout << " char is " << noparenthesis[i] << endl;
            //cout << " erasing " << parenthesis.top() << endl;

            parenthesis.pop();
        }else


        if( noparenthesis[i] == ']' && parenthesis.top() == '[' )
        {

            //cout << " char is " << noparenthesis[i] << endl;
            //cout << " erasing " << parenthesis.top() << endl;

            parenthesis.pop();
        }
          else
        {
            return false;
        }

        } // if
        else
        {
            return false;
        }

        forloop++;

        //cout << " forloop is " << forloop << endl;


    }// for


    //cout << "size is " << parenthesis.size() << endl;

    if ( parenthesis.size() == 0 )
    {

         //cout << " return true\n" << endl;

         return true;
    }else


    if ( parenthesis.size() != 0 )
    {

         //cout << " return false\n" << endl;

         return false;
    }

}// function






virtual string infixToPostfix(string infixExpression)
{

  //cout << "   the expression is " << infixExpression << endl;

    bool oper_bala;
    oper_bala = operators_unbalanced( infixExpression);
    if (oper_bala == true){ return "invalid";}




    if (oper_bala == false)
    {
      //cout << "   the oper_bala is false" << endl;
    } else
    if (oper_bala == true)
    {
      //cout << "   the oper_bala is true" << endl;
    }







    bool parenthesis = isBalanced(infixExpression);



    if (parenthesis == false)
    {
      //cout << "   the boolparenthesis is false" << endl;
    } else
    if (parenthesis == true)
    {
      //cout << "   the boolparenthesis is true" << endl;
    }



    bool allrnumbers = goodcharacters (infixExpression);



    if (allrnumbers == false)
    {
    //cout << "   allrnumbers is false" << endl;
    } else
    if (allrnumbers == true)
    {
      //cout << "   allrnumbers is true" << endl;
    }



    if ( parenthesis == true && allrnumbers == true)
    {

    stack<char> operators;
    int x = 0;


    bool mult_stri;
    bool sums_stri;
    bool open_pare_stri;
    bool clos_pare_stri;
    bool nums_stri;



    bool mult_stac;
    bool sums_stac;
    bool open_pare_stac;
    bool clos_pare_stac;

    for ( int i = 0 ; i+x < infixExpression.length() ; i++)
    {
        //cout << endl << " in for" << endl;
        //cout << " infixExpression is " << infixExpression[i+x] << endl;


        if (operators.empty() == false && stringstack.empty() == false)
        {
        //cout << " top of operators is " << operators.top() << endl;
        //cout << " top of stringstack is " << stringstack.top() << endl;
        }



        mult_stri = false;
        sums_stri = false;
        open_pare_stri = false;
        clos_pare_stri = false;
        nums_stri = false;



        mult_stac = false;
        sums_stac = false;
        open_pare_stac = false;
        clos_pare_stac = false;



        if (infixExpression[i+x] == '}' || infixExpression[i+x] == ')' || infixExpression[i+x] == ']')
        { clos_pare_stri = true;}


        if (infixExpression[i+x] == '{' || infixExpression[i+x] == '(' || infixExpression[i+x] == '[')
        { open_pare_stri = true;}


        if (infixExpression[i+x] == '+' || infixExpression[i+x] == '-')
        { sums_stri = true;}


        if (infixExpression[i+x] == '*' || infixExpression[i+x] == '/' || infixExpression[i+x] == '%')
        { mult_stri = true;}


        if (infixExpression[i+x] == '1' || infixExpression[i+x] == '2' || infixExpression[i+x] == '3' || infixExpression[i+x] =='4' || infixExpression[i+x] =='5' || infixExpression[i+x] =='6' ||infixExpression[i+x] =='7' || infixExpression[i+x] =='8' || infixExpression[i+x] =='9' || infixExpression[i+x] =='0')
        { nums_stri = true;}


        if (operators.empty() == false)
        {

            if (operators.top() == '{' || operators.top() == '(' || operators.top() == '[')
            { open_pare_stac = true;}


            if (operators.top() == '}' || operators.top() == ')' || operators.top() == ']')
            { clos_pare_stac = true;}


            if (operators.top() == '+' || operators.top() == '-')
            { sums_stac = true;}


            if (operators.top() == '*' || operators.top() == '/' || operators.top() == '%')
            { mult_stac = true;}

        }



        //cout << "1 is true, and 0 is false" << endl;
        //cout << "* string " << mult_stri << endl;
        //cout << "+ string " << sums_stri << endl;
        //cout << "( string " << open_pare_stri << endl;
        //cout << ") string " << clos_pare_stri << endl;
        //cout << "1 string " << nums_stri << endl;
        //cout << "* stack  " << mult_stac << endl;
        //cout << "+ stack  " << sums_stac << endl;
        //cout << "( stack  " << open_pare_stac << endl;
        //cout << ") stack  " << clos_pare_stac << endl;







        if (infixExpression[i+x] == ' ')
        {

        }




        if (nums_stri == true)
        {
            string bignumber;

            while ( infixExpression[i+x] != ' ' && i+x < infixExpression.length())
            {
                string new1 = char_string(infixExpression[i+x]);
                bignumber = bignumber +  new1;
                x = x + 1 ;
            }
            //cout << "numeros" << endl;

            stringstack.push(bignumber);
            stringstack.push(" ");
           // cout << "this was push to string " << bignumber << endl;
        }




        if (operators.size() == 0)
        {
        if (sums_stri == true || mult_stri == true ) //|| open_pare_stri == true
        {
            //cout << "operator is " << infixExpression[i+x] << endl;
            operators.push(infixExpression[i+x]);
            //cout << "operator inside is " << operators.top() << endl;
            //cout << "this was push to string 'nothing'"  << endl;
        }
        }



        if (mult_stri == true)
        {
            //cout << "inside * function" << endl;
        if (sums_stac == true || open_pare_stac == true)
        {
            //cout << " stri * , stac +" << endl;
            string oper = char_string(operators.top());
            //stringstack.push(oper);
            //stringstack.push(" ");
            //operators.pop();
            operators.push(infixExpression[i+x]);
            //cout << "this was push to string 'nothing'" << endl;
        }
        }




        if (sums_stri == true)
        {
            //cout << "inside + finction" << endl;
        if (mult_stac == true )
        {
            //cout << "stri + , stac *" << endl;
            //operators.push(infixExpression[i+x]);

            string oper = char_string(operators.top());
            stringstack.push(oper);
            stringstack.push(" ");
            operators.pop();
            operators.push(infixExpression[i+x]);
            //cout << " operator added is " << infixExpression[i+x] << endl;
            //cout << "this was push to string " << oper << endl;
        }

        if (open_pare_stac == true)
        {
            //cout << "stri + , stac (" << endl;
            operators.push(infixExpression[i+x]);
            //cout << " operator added is " << infixExpression[i+x] << endl;
            //cout << "this was push to string 'nothing'" << endl;
        }
        }


         //new
        if ( mult_stri == true && mult_stac == true)
        {
            //cout << "* == *" << endl;
            string oper = char_string(operators.top());
            stringstack.push(oper);
            stringstack.push(" ");
            operators.pop();
            operators.push(infixExpression[i+x]);
            //cout << "this was push to string " << oper << endl;
        }




        if ( sums_stri == true && sums_stac == true)
        {
            //cout << "+ == +" << endl;
            string oper = char_string(operators.top());
            stringstack.push(oper);
            stringstack.push(" ");
            operators.pop();
            operators.push(infixExpression[i+x]);
            //cout << "this was push to string " << oper << endl;
        }



        //if (operators.size() < 0)
        //{
        if (open_pare_stri == true)
        {
            //cout << "(" << endl;
            operators.push(infixExpression[i+x]);
            //cout << " inside" << infixExpression[i+x] << endl;
            //cout << "this was push to string 'nothing'" << endl;
        }
        //}



        if ( clos_pare_stri == true )
        {
            //cout << ")" << endl;
            bool whil =  false;
            while(whil == false)
            {
                string oper = char_string(operators.top());
                stringstack.push(oper);
                stringstack.push(" ");
                operators.pop();
                //cout << "this was push to string " << oper << endl;
                if (operators.top() != '(' || operators.top() != '{' || operators.top() != '[')
                { whil = true;}
            }
            operators.pop(); // gets rid of the ( on top

        }




        if (infixExpression[i+x] == infixExpression[infixExpression.length()])
        {
            //cout << "length is zero" << endl;

            while (operators.size() != 0)
            {
                string oper = char_string(operators.top());
                stringstack.push(oper);
                stringstack.push(" ");
                operators.pop();
                //cout << "this was push to string " << oper << endl;
            }
            stringstack.pop();
        }






    } // for infixExpression[i]




    stack<string> flipping;
    int size = stringstack.size();
    //cout << "this is size " << size << endl;
    for ( int i = 0 ; i < size ; i++)
    {
        //cout << stringstack.top();
        flipping.push(stringstack.top());
        //cout << flipping.top();
        stringstack.pop();
    }




    string answ;
    string elem;
    int size2 = flipping.size();
    //cout << endl << "this is size2 " << size << endl;
    for ( int i = 0 ; i < size2 ; i++)
    {
        //cout << flipping.top();
        elem = flipping.top();
        answ = answ + elem;
        flipping.pop();
    }



    return answ;



    }

    return "invalid";

} // function


virtual string postfixToInfix(string postfixExpression)
{

bool oper_bala;
    oper_bala = operators_unbalanced( postfixExpression);
    if (oper_bala == true){ return "invalid";}

    if (postfixExpression[0] == '+' || postfixExpression[0] == '-' || postfixExpression[0] == '*' || postfixExpression[0] == '/' || postfixExpression[0] == '%')
    { return "invalid";}

    int end1 = postfixExpression.length() -1;

    if (postfixExpression[end1] == '1' ||
        postfixExpression[end1] == '2' ||
        postfixExpression[end1] == '3' ||
        postfixExpression[end1] == '4' ||
        postfixExpression[end1] == '5' ||
        postfixExpression[end1] == '6' ||
        postfixExpression[end1] == '7' ||
        postfixExpression[end1] == '8' ||
        postfixExpression[end1] == '9' ||
        postfixExpression[end1] == '0' ) { return "invalid";}

stack<string> stri_stac;

//cout << "   the expression is " << postfixExpression << endl;

            int x = 0;

            for ( int a = 0 ; ( a + x ) < postfixExpression.length() ; a++)
            {
            string bignumber = "";
            while ( postfixExpression[x + a] != ' ' && x + a < postfixExpression.length())
            {

                string new1 = char_string(postfixExpression[x + a]);
                if(new1 == ".") {return "invalid";}
                bignumber = bignumber +  new1;
                x = x + 1 ;
            //cout << "this is going to the stack" << bignumber << endl;
            }
            //cout << "numeros" << endl;
            stri_stac.push(bignumber);
            //cout << "this is inside the stack" << stri_stac.top() << endl;
            }


    stack<string> flipping;
    int size2 = stri_stac.size();
    //cout << "this is size " << size << endl;
    for ( int i = 0 ; i < size2 ; i++)
    {
        //cout << stringstack.top();
        flipping.push(stri_stac.top());
        //cout << flipping.top();
        stri_stac.pop();
        //cout << "this is inside of flipping" << flipping.top() << endl;
    }





            stack<string> post_infi;
            bool nums_stri;
            bool oper_stri;
            int size1 = flipping.size();

            for ( int a = 0 ; a < size1 ; a++)
            {

            oper_stri = false;
            nums_stri = false;

            if (flipping.top() == "*" || flipping.top() == "/" || flipping.top() == "%" || flipping.top() == "-" || flipping.top() == "+")
            { oper_stri = true;}
            else
            { nums_stri = true;}


            if (nums_stri == true)
            {
            post_infi.push(flipping.top());
            flipping.pop();
            //cout << "this was inserted in post_infi " << post_infi.top() << endl;
            }

            if (oper_stri == true)
            {
            string righ;
            string left;
            string oper;
            string all;

            oper = flipping.top();
            //cout << " this is the oper " << oper << endl;
            flipping.pop();

            righ = post_infi.top(); post_infi.pop();
            //cout << " this is righ " << righ << endl;

            left = post_infi.top(); post_infi.pop();
            //cout << " this is left " << left << endl;

            all = "( " + left  + " " + oper + " " + righ + " " + ")";
            post_infi.push(all);
            //cout << "this is all " << post_infi.top() << endl;

            } // if



        }// while

if ( post_infi.size() > 1) {return "invalid";}
string all_Nspa = post_infi.top();
//cout << "this is all_Nspa " << all_Nspa << endl;

           /* string all_stac;
            while ( post_infi.size() != 0)
            {
            all_stac = all_stac + post_infi.top();
            post_infi.pop();

            }
*/

            /*string all_spac;
            for ( int i = 0; i < all_Nspa.length() - 1 ; i++)
            {
            all_spac = all_Nspa[i] + " ";
            cout << "this is all_spac " << all_spac << endl;
            }
cout << "this is final all_spac " << all_spac << endl;*/

    return all_Nspa;


}


virtual string postfixEvaluate(string postfixExpression)
{

    //bool oper_bala;
    //oper_bala = operators_unbalanced( postfixExpression);
    //if (oper_bala == true){ return "invalid";}

    if (postfixExpression[0] == '+' || postfixExpression[0] == '-' || postfixExpression[0] == '*' || postfixExpression[0] == '/' || postfixExpression[0] == '%')
    { return "invalid";}

 if (postfixExpression[0] == '(' || postfixExpression[0] == ')' || postfixExpression[0] == '[' || postfixExpression[0] == ']' || postfixExpression[0] == '{' || postfixExpression[0] == '}')
    { return "invalid";}


if (postfixExpression.length() < 6)
{
string result;
result = char_string(postfixExpression[0]);
return result;
}

    int end1 = postfixExpression.length() -1;

    if (postfixExpression[end1] == '1' ||
        postfixExpression[end1] == '2' ||
        postfixExpression[end1] == '3' ||
        postfixExpression[end1] == '4' ||
        postfixExpression[end1] == '5' ||
        postfixExpression[end1] == '6' ||
        postfixExpression[end1] == '7' ||
        postfixExpression[end1] == '8' ||
        postfixExpression[end1] == '9' ||
        postfixExpression[end1] == '0' ) { return "invalid";}


//cout << "this is the espression " << postfixExpression << endl;
stack<string> stri_stac;
 int x = 0;

            for ( int a = 0 ; ( a + x ) < postfixExpression.length() ; a++)
            {
            string bignumber = "";
            while ( postfixExpression[x + a] != ' ' && x + a < postfixExpression.length())
            {

                string new1 = char_string(postfixExpression[x + a]);
                if(new1 == ".") {return "invalid";}
                bignumber = bignumber +  new1;
                x = x + 1 ;
            //cout << "this is going to the stack" << bignumber << endl;
            }
            //cout << "numeros" << endl;
            stri_stac.push(bignumber);
            //cout << "this is inside the stack" << stri_stac.top() << endl;
            }






    stack<int> flipping2;
    stack<string> flipping;
    int size2 = stri_stac.size();
    //cout << "this is size " << size << endl;
    for ( int i = 0 ; i < size2 ; i++)
    {
     /*if (stri_stac.top() != "+" && stri_stac.top() != "-" && stri_stac.top() != "*" && stri_stac.top() != "/" && stri_stac.top() != "%")
    {
        int temp = string_int(stri_stac.top());
        flipping2.push(temp);
        cout << "this is inside of flipping2  " << flipping2.top() << endl;
    }*/

        flipping.push(stri_stac.top());
        //cout << flipping.top();
        stri_stac.pop();
        //cout << "this is inside of flipping  " << flipping.top() << endl;

    }






//return " ";


            int size1 = flipping.size();

            while ( flipping.size() != 0)
            {
            //cout << " in for " << endl;

            if (flipping.top() != "+" && flipping.top() != "-" && flipping.top() != "*" && flipping.top() != "/" && flipping.top() != "%")
            {
                int temp = string_int(flipping.top());
                flipping2.push(temp);
               // cout << "this is inside of flipping2  " << flipping2.top() << endl;
            }



            if (flipping.top() == "*" )
            {

            //cout << " *** " << endl;


            int righ = 0;
            int left = 0;
            int all = 0;

            righ = flipping2.top(); flipping2.pop();
            //cout << " this is righ " << righ << endl;

            left = flipping2.top(); flipping2.pop();
            //cout << " this is left " << left << endl;

            all = left * righ;
            flipping2.push(all);
           // cout << "this is all " << flipping2.top() << endl;
            flipping.pop();


            }else



            if (flipping.top() == "/")
            {

           // cout << " /// " << endl;


            int righ = 0;
            int left = 0;
            int all = 0;

            righ = flipping2.top(); flipping2.pop();
           // cout << " this is righ " << righ << endl;

            left = flipping2.top(); flipping2.pop();
            //cout << " this is left " << left << endl;

            if (left == 0 )
            {
            all = 0;
            }
            if (righ == 0 )
            {
            return "invalid";

            }
            else
            {
            all = left / righ;
            }

            flipping2.push(all);
            //cout << "this is all " << flipping2.top() << endl;


            flipping.pop();
            } else



            if (flipping.top() == "%")
            {

            //cout << " %%% " << endl;
            //cout << " top of flipping " << flipping.top() << endl;
            //cout << " top of flipping2 " << flipping2.top() << endl;

            int righ = 0;
            int left = 0;
            int all = 0;

            righ = flipping2.top(); flipping2.pop();
            //cout << " this is righ " << righ << endl;
            //cout << " top of flipping2 second time " << flipping2.top() << endl;
            left = flipping2.top(); flipping2.pop();
           // cout << " this is left " << left << endl;

            all = left % righ;


            flipping2.push(all);
            //cout << "this is all " << flipping2.top() << endl;


            flipping.pop();
            } else




            if (flipping.top() == "+")
            {

            //cout << " +++ " << endl;


            int righ = 0;
            int left = 0;
            int all = 0;

            righ = flipping2.top(); flipping2.pop();
           // cout << " this is righ " << righ << endl;

            left = flipping2.top(); flipping2.pop();
            //cout << " this is left " << left << endl;

            all = left + righ;
            flipping2.push(all);
            //cout << "this is all " << flipping2.top() << endl;


            flipping.pop();
            }else



            if (flipping.top() == "-")
            {

            //cout << " --- " << endl;


            int righ = 0;
            int left = 0;
            int all = 0;

            righ = flipping2.top(); flipping2.pop();
            //cout << " this is righ " << righ << endl;

            left = flipping2.top(); flipping2.pop();
            //cout << " this is left " << left << endl;

            all = left - righ;
            flipping2.push(all);
            //cout << "this is all " << flipping2.top() << endl;


            flipping.pop();

            } else// if



            {
            flipping.pop();
            }

        }// while

//cout << "result " << flipping2.top() << endl;
string result = int_string (flipping2.top());

    return result;

}


bool goodcharacters ( string infixExpression)
{
 bool allrnumbers = true;


    for ( int i = 0 ; i < infixExpression.length() ; i++ )
    {
       if (infixExpression[i] != '1' &&
           infixExpression[i] != '2' &&
           infixExpression[i] != '3' &&
           infixExpression[i] != '4' &&
           infixExpression[i] != '5' &&
           infixExpression[i] != '6' &&
           infixExpression[i] != '7' &&
           infixExpression[i] != '8' &&
           infixExpression[i] != '9' &&
           infixExpression[i] != '0' &&
           infixExpression[i] != '+' &&
           infixExpression[i] != '-' &&
           infixExpression[i] != '*' &&
           infixExpression[i] != '/' &&
           infixExpression[i] != '%' &&
           infixExpression[i] != '(' &&
           infixExpression[i] != ')' &&
           infixExpression[i] != '{' &&
           infixExpression[i] != '}' &&
           infixExpression[i] != '[' &&
           infixExpression[i] != ']' &&
           infixExpression[i] != ' ' ) {allrnumbers = false; break;}
    } // for
 return allrnumbers;
} // function

string char_string ( char algo )
{
          if (algo == '1' ) {return "1";}
          if (algo == '2' ) {return "2";}
          if (algo == '3' ) {return "3";}
          if (algo == '4' ) {return "4";}
          if (algo == '5' ) {return "5";}
          if (algo == '6' ) {return "6";}
          if (algo == '7' ) {return "7";}
          if (algo == '8' ) {return "8";}
          if (algo == '9' ) {return "9";}
          if (algo == '0' ) {return "0";}
          if (algo == '+' ) {return "+";}
          if (algo == '-' ) {return "-";}
          if (algo == '*' ) {return "*";}
          if (algo == '/' ) {return "/";}
          if (algo == '%' ) {return "%";}
          if (algo == '(' ) {return "(";}
          if (algo == ')' ) {return ")";}
          if (algo == '{' ) {return "{";}
          if (algo == '}' ) {return "}";}
          if (algo == '[' ) {return "[";}
          if (algo == ']' ) {return "]";}
          if (algo == '.' ) {return ".";}
}

bool operators_unbalanced ( string algo)
{


    stack<string> temp_stri;
    stack<char> temp_oper;
    bool nums_stri;
    int x = 0;


    for (int i = 0; i+x < algo.length() ; i++)
    {
        nums_stri = false;

     if (algo[i+x] == '1' || algo[i+x] == '2' || algo[i+x] == '3' || algo[i+x] =='4' || algo[i+x] =='5' || algo[i+x] =='6' ||algo[i+x] =='7' || algo[i+x] =='8' || algo[i+x] =='9' || algo[i+x] =='0')
        { nums_stri = true;}


    if (algo[i+x] == ' ')
    {

    }
    else


    if (nums_stri == true)
        {
            string bignumber;

            while ( algo[i+x] != ' ' && i+x < algo.length())
            {
                string new1 = char_string(algo[i+x]);
                bignumber = bignumber +  new1;
                x = x + 1 ;
            }
            //cout << "numeros" << endl;
            //cout << "bignumber is " << bignumber << endl;
            temp_stri.push(bignumber);
            //stringstack.push(" ");
        } else

        {

          if (algo[i+x] == '+' ) {temp_oper.push('+');}
          if (algo[i+x] == '-' ) {temp_oper.push('-');}
          if (algo[i+x] == '*' ) {temp_oper.push('*');}
          if (algo[i+x] == '/' ) {temp_oper.push('/');}
          if (algo[i+x] == '%' ) {temp_oper.push('%');}

        }



    if (temp_oper.empty() == false && temp_stri.empty() == false)
    {
    //cout << "top of temp_oper is " << temp_oper.top() << endl;
    //cout << "top of temp_stri is " << temp_stri.top() << endl;



    if (temp_oper.top() == ' ') { temp_oper.pop();}
    if (temp_stri.top() == " ") { temp_stri.pop();}
    }





    } //for

    //cout << "temp_stri size is " << temp_stri.size() << endl;
    //cout << "temp_oper size is " << temp_oper.size() << endl;


    if (temp_stri.size() == 0)
    {
        return true;
    }


    if (temp_oper.size() == 0)
    {
        return true;
    }



    if (temp_stri.size() == temp_oper.size())
    {
        return true;
    }


        return false;

} // function


int string_int (string a)
{

if (a == "0") {return 0;}
if (a == "1") {return 1;}
if (a == "2") {return 2;}
if (a == "3") {return 3;}
if (a == "4") {return 4;}
if (a == "5") {return 5;}
if (a == "6") {return 6;}
if (a == "7") {return 7;}
if (a == "8") {return 8;}
if (a == "9") {return 9;}

if (a == "10") {return 10;}
if (a == "11") {return 11;}
if (a == "12") {return 12;}
if (a == "13") {return 13;}
if (a == "14") {return 14;}
if (a == "15") {return 15;}
if (a == "16") {return 16;}
if (a == "17") {return 17;}
if (a == "18") {return 18;}
if (a == "19") {return 19;}

if (a == "20") {return 20;}
if (a == "21") {return 21;}
if (a == "22") {return 22;}
if (a == "23") {return 23;}
if (a == "24") {return 24;}
if (a == "25") {return 25;}
if (a == "26") {return 26;}
if (a == "27") {return 27;}
if (a == "28") {return 28;}
if (a == "29") {return 29;}

if (a == "30") {return 30;}
if (a == "31") {return 31;}
if (a == "32") {return 32;}
if (a == "33") {return 33;}
if (a == "34") {return 34;}
if (a == "35") {return 35;}
if (a == "36") {return 36;}
if (a == "37") {return 37;}
if (a == "38") {return 38;}
if (a == "39") {return 39;}


if (a == "40") {return 40;}
if (a == "41") {return 41;}
if (a == "42") {return 42;}
if (a == "43") {return 43;}
if (a == "44") {return 44;}
if (a == "45") {return 45;}
if (a == "46") {return 46;}
if (a == "47") {return 47;}
if (a == "48") {return 48;}
if (a == "49") {return 49;}


if (a == "50") {return 50;}
if (a == "51") {return 51;}
if (a == "52") {return 52;}
if (a == "53") {return 53;}
if (a == "54") {return 54;}
if (a == "55") {return 55;}
if (a == "56") {return 56;}
if (a == "57") {return 57;}
if (a == "58") {return 58;}
if (a == "59") {return 59;}

if (a == "60") {return 60;}
if (a == "61") {return 61;}
if (a == "62") {return 62;}
if (a == "63") {return 63;}
if (a == "64") {return 64;}
if (a == "65") {return 65;}
if (a == "66") {return 66;}
if (a == "67") {return 67;}
if (a == "68") {return 68;}
if (a == "69") {return 69;}

if (a == "70") {return 70;}
if (a == "71") {return 71;}
if (a == "72") {return 72;}
if (a == "73") {return 73;}
if (a == "74") {return 74;}
if (a == "75") {return 75;}
if (a == "76") {return 76;}
if (a == "77") {return 77;}
if (a == "78") {return 78;}
if (a == "79") {return 79;}

if (a == "80") {return 80;}
if (a == "81") {return 81;}
if (a == "82") {return 82;}
if (a == "83") {return 83;}
if (a == "84") {return 84;}
if (a == "85") {return 85;}
if (a == "86") {return 86;}
if (a == "87") {return 87;}
if (a == "88") {return 88;}
if (a == "89") {return 89;}

if (a == "90") {return 90;}
if (a == "91") {return 91;}
if (a == "92") {return 92;}
if (a == "93") {return 93;}
if (a == "94") {return 94;}
if (a == "95") {return 95;}
if (a == "96") {return 96;}
if (a == "97") {return 97;}
if (a == "98") {return 98;}
if (a == "99") {return 99;}
if (a == "100") {return 100;}
}

string int_string (int a)
{

if (a == 0) {return "0";}
if (a == 1) {return "1";}
if (a == 2) {return "2";}
if (a == 3) {return "3";}
if (a == 4) {return "4";}
if (a == 5) {return "5";}
if (a == 6) {return "6";}
if (a == 7) {return "7";}
if (a == 8) {return "8";}
if (a == 9) {return "9";}

if (a == 10) {return "10";}
if (a == 11) {return "11";}
if (a == 12) {return "12";}
if (a == 13) {return "13";}
if (a == 14) {return "14";}
if (a == 15) {return "15";}
if (a == 16) {return "16";}
if (a == 17) {return "17";}
if (a == 18) {return "18";}
if (a == 19) {return "19";}

if (a == 20) {return "20";}
if (a == 21) {return "21";}
if (a == 22) {return "22";}
if (a == 23) {return "23";}
if (a == 24) {return "24";}
if (a == 25) {return "25";}
if (a == 26) {return "26";}
if (a == 27) {return "27";}
if (a == 28) {return "28";}
if (a == 29) {return "29";}

if (a == 30) {return "30";}
if (a == 31) {return "31";}
if (a == 32) {return "32";}
if (a == 33) {return "33";}
if (a == 34) {return "34";}
if (a == 35) {return "35";}
if (a == 36) {return "36";}
if (a == 37) {return "37";}
if (a == 38) {return "38";}
if (a == 39) {return "39";}

if (a == 40) {return "40";}
if (a == 41) {return "41";}
if (a == 42) {return "42";}
if (a == 43) {return "43";}
if (a == 44) {return "44";}
if (a == 45) {return "45";}
if (a == 46) {return "46";}
if (a == 47) {return "47";}
if (a == 48) {return "48";}
if (a == 49) {return "49";}

if (a == -91) {return "-91";}
if (a == -100) {return "-100";}

}
    private:

    stack<string> stringstack;







    };






















#ifdef	__cplusplus
}
#endif

#endif	/* EXPRESSIONMANAGER_H */

