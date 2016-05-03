#ifndef __BITFIELD_H__
#define __BITFIELD_H__

#include <iostream>

using namespace std;
typedef unsigned int TELEM;

class TBitField
{
private:
  int  BitLen;
  TELEM *pMem;
  int  MemLen;
public:
  int  GetMemLen(void) const;
  int  GetMemIndex(const int n) const;       
  TELEM GetMemMask (const int n) const;       
  ~TBitField();
  TBitField(int len);                                            
  TBitField(const TBitField &bf);
                                                
  int GetLength(void) const;
  void SetBit(const int n);
  void ClrBit(const int n);                     
  int  GetBit(const int n) const;

  bool operator==(const TBitField &bf) const;        
  bool operator!=(const TBitField &bf) const;
  TBitField& operator=(const TBitField &bf);          
  TBitField  operator|(const TBitField &bf);        
  TBitField  operator&(const TBitField &bf);             
  TBitField  operator~(void);
};
#endif

