/* <!-- copyright */
/*
 * aria2 - a simple utility for downloading files faster
 *
 * Copyright (C) 2006 Tatsuhiro Tsujikawa
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
/* copyright --> */
#ifndef _D_SHA_VISITOR_H_
#define _D_SHA_VISITOR_H_

#include "MetaEntryVisitor.h"
#include "Data.h"
#include "Dictionary.h"
#include "List.h"
#include "common.h"
#ifdef HAVE_LIBSSL
#include <openssl/evp.h>
#endif // HAVE_LIBSSL

class ShaVisitor : public MetaEntryVisitor {
private:
#ifdef HAVE_LIBSSL
  EVP_MD_CTX ctx;
#endif // HAVE_LIBSSL
public:
  ShaVisitor();
  ~ShaVisitor();

  void visit(const Data* d);
  void visit(const Dictionary* d);
  void visit(const List* l);
  void visit(const MetaEntry* e);

  void getHash(unsigned char* md, int& s);
};

#endif // _D_SHA_VISITOR_H_
