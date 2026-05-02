====================================================================================================================
1. Common Smart Pointer Methods:
These are used across unique_ptr and shared_ptr:

✅ get() --------------------------------------------------------------------

👉 Returns raw pointer (does NOT transfer ownership)
auto p = make_unique<int>(10);
int* raw = p.get();

------------------------------------------------------------------------------

✅ reset()
👉 Deletes current object and optionally assigns new one
p.reset();              // deletes object
p.reset(new int(20));   // replace with new object

------------------------------------------------------------------------------

✅ release() (ONLY for unique_ptr)
👉 Releases ownership and returns raw pointer
auto p = make_unique<int>(10);
int* raw = p.release(); // now YOU must delete raw
⚠️ After this → p becomes nullptr

------------------------------------------------------------------------------

✅ move()
👉 Transfers ownership (used with unique_ptr)
auto p2 = move(p1);

------------------------------------------------------------------------------

✅ swap()
👉 Swap ownership between two pointers
p1.swap(p2);

====================================================================================================================

🔹 2. Methods specific to shared_ptr
✅ use_count()
👉 Number of shared owners
shared_ptr<int> p1 = make_shared<int>(10);
shared_ptr<int> p2 = p1;
cout << p1.use_count(); // 2

------------------------------------------------------------------------------

✅ unique()
👉 Check if only one owner exists
if (p1.unique()) {
    cout << "Only one owner";
}

====================================================================================================================

🔹 3. Accessing object
✅ -> operator
p->area();

------------------------------------------------------------------------------

✅ * operator
cout << *p;

====================================================================================================================

🔥 Important Summary Table ----------------------------------------------------------------------------------------

Method            	unique_ptr	                 shared_ptr                           	Use
get()                 	✅	                       ✅                        	Access raw pointer
reset()	                ✅                          ✅	                        Delete / replace
release()           	✅                          ❌                          	Give up ownership
move()	                ✅	                       ❌ (not needed)	            Transfer ownership
use_count()         	❌	                       ✅	                        Count owners
unique()            	❌                          ✅                          	Check single owner
swap()              	✅	                       ✅                           	Swap pointers

-------------------------------------------------------------------------------------------------------------------
====================================================================================================================