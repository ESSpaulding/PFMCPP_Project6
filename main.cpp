/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert all of the pointer usage (except for 'const char*') to reference types or
    const reference types **>>> WHERE POSSIBLE <<<**
        hint: There is no reference equivalent to nullptr.
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.
 
 2) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */


#include <iostream>
#include <string>
struct T
{
    T(int v, const char* w) : value(v), name(w)
    {
        
    }//1
    int value; //2
    std::string name; //3
};

struct Lesser                                //4
{
    T* compare(T& a, T& b) //5        // 1) Doesn't need to be converted to a reference because compare returns a nullptr
    {
        if( a.value < b.value ) return &a;
        if( a.value > b.value ) return &b;
        return nullptr;
    }
};

struct U
{
    float terry { 0 }, todd { 0 };
    float memberFunc(float& updatedValue)      //12
    {
        std::cout << "U's terry value: " << terry << std::endl;  //'->' is the member-of-pointer operator
        terry = updatedValue;
        std::cout << "U's terry updated value: " << terry << std::endl;
        while( std::abs(todd - terry) > 0.001f )
        {
            //std::cout << "MFtodd: " << todd << " MFterry: " << terry << std::endl;
            todd += terry / 3;   // distance between terry and todd drops
        }
        return todd * terry;
    }
};

struct Struct2
{
    static float statFuncA(U& that, float& updatedValue )        //10    //passes pointer to object so objects updated value can be modified
    {
        
        std::cout << "U's terry value: " << that.terry << std::endl;
        that.terry = updatedValue;
        std::cout << "U's terry updated value: " << that.terry << std::endl;
        while( std::abs(that.todd - that.terry) > 0.001f )
        {
            //std::cout << "SFtodd: " << that.todd << " SFterry: " << that.terry << std::endl;
            that.todd += that.terry / 3;
        }
        std::cout << "U's todd updated value: " << that.todd << std::endl;
      
        return that.todd * that.terry;
    }
};
        
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already:
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.
 send me a DM to review your pull request when the project is ready for review.
 Wait for my code review.
 */

int main()
{
    T terry( 16 , "Terry" );
    T todd( 3, "Todd" );
    
    Lesser f;
    auto* smaller = f.compare(terry ,todd );                             // return type is a pointer to an address of or nullptr
    if (smaller != nullptr)
    {
        std::cout << "the smaller one is << " << smaller->name << std::endl;
    }
    U uri;
    float updatedValue = 5.f;
    std::cout << "[static func] uri's multiplied values: " << Struct2::statFuncA(uri, updatedValue) << std::endl;                  //11

    U uli;
    std::cout << "[member func] uli's multiplied values: " << uli.memberFunc( updatedValue ) << std::endl;
}

        
