#include "primitives.hpp"
#include <vector>
#include <sstream>


class References {
    /**
     * Object used to parse references from a paper's PDF.
     * 
     * A ``References`` object is given a ``Paper`` P and must create a list of
     * ``Paper``s which are referenced by P. It must call arxiv to download the
     * pdf associated to P, extract the text from this pdf and look for
     * reference string patterns.
     */

    private:
    /**
     * Private variables:
     *      - ``references``: holds parsed references.
     *      - ``textBuffer``: text of paper's pdf.
     */
    std::vector<Reference> references;
    std::stringstream textBuffer;

    public:
    /**
     * Iterator functionality.
     * Simple delegation to the underlying ``references`` vector. Give this no
     * thought when developing this object, only when using it.
     */
    typedef std::vector<Reference>::iterator iterator;
    iterator begin() { return this->references.begin(); }
    iterator end() { return this->references.end(); }

    /**
     * Called by libcurl when data is received. This function must convert
     * the pdf bytes to text incrementally (as the data arrives). This requires
     * some thought but is doable.
     *
     * The motivation behind this is that It is more efficient than waiting for
     * all the data before converting (look up non-blokcing IO).
     *
     * The text data must be stored in ``textBuffer``.
     */
    static std::size_t fillBuffer(
        void *contents,
        std::size_t size,
        std::size_t nmemb,
        std::stringstream *buf);  // buf will be a pointer to ``textBuffer``

    /**
     * Assuming ``textBuffer`` has been completely filled, get all arxiv
     * references and store them in ``references``.
     */
    void getReferences();

    /**
     * Constructor.
     * 
     * Must call arxiv to download the pdf and convert it to text through
     * ``fillBuffer``. Once this process is over, the constructor must call
     * ``getReferences`` to fill up the ``references`` vector.
     * 
     * The constructor ensures that the object may be iterated over and
     * immediately yield all found references in ``paper``.
     
   Yassine Marakchi and Maria benkhadra
     */
    
    
    
    
#include <iostream>
#include <string>
#include <vector>

{
  std::vector<std::string> seen;
  std::string str="our script arXiv:xxxx.xxxxxx puis our script2 arXiv:xxxx.bbbbbb";
  
  while (true){
      int pos = str.find("arXiv:");
      if (pos == std::string::npos ){
          break;
      }
   seen.push_back(str.substr(pos, 17));
      str = str.substr(pos + 17);
  }
std::cout << seen[1];  /*seen is our vector with all the refrences, in this case it prints the second reference*/
  return 0;
}
    References(Paper paper);
};
