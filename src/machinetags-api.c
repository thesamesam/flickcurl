/* -*- Mode: c; c-basic-offset: 2 -*-
 *
 * machinetags-api.c - Flickr flickr.machinetags.* API calls
 *
 * Copyright (C) 2008, David Beckett http://www.dajobe.org/
 * 
 * This file is licensed under the following three licenses as alternatives:
 *   1. GNU Lesser General Public License (LGPL) V2.1 or any newer version
 *   2. GNU General Public License (GPL) V2 or any newer version
 *   3. Apache License, V2.0 or any newer version
 * 
 * You may not use this file except in compliance with at least one of
 * the above three licenses.
 * 
 * See LICENSE.html or LICENSE.txt at the top of this package for the
 * complete terms and further detail along with the license texts for
 * the licenses in COPYING.LIB, COPYING and LICENSE-2.0.txt respectively.
 * 
 */

#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#undef HAVE_STDLIB_H
#endif
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

#include <flickcurl.h>
#include <flickcurl_internal.h>


/**
 * flickcurl_machinetags_getNamespaces:
 * @fc: flickcurl context
 * @predicate: Limit the list of namespaces returned to those that have the following predicate (or NULL)
 * @per_page: Number of photos to return per page. If this argument is omitted, it defaults to 100. The maximum allowed value is 500 (or NULL)
 * @page: The page of results to return. If this argument is omitted, it defaults to 1 (or NULL)
 * 
 * Return a list of unique namespaces, optionally limited by a given predicate, in alphabetical order.
 *
 * Implements flickr.machinetags.getNamespaces (1.7)
 * 
 * Return value: non-0 on failure
 **/
int
flickcurl_machinetags_getNamespaces(flickcurl* fc, const char* predicate,
                                    const char* per_page, const char* page)
{
  const char* parameters[10][2];
  int count=0;
  xmlDocPtr doc=NULL;
  xmlXPathContextPtr xpathCtx=NULL; 
  void* result=NULL;
  
  parameters[count][0]  = "predicate";
  parameters[count++][1]= predicate;
  parameters[count][0]  = "per_page";
  parameters[count++][1]= per_page;
  parameters[count][0]  = "page";
  parameters[count++][1]= page;

  parameters[count][0]  = NULL;

  if(flickcurl_prepare(fc, "flickr.machinetags.getNamespaces", parameters, count))
    goto tidy;

  doc=flickcurl_invoke(fc);
  if(!doc)
    goto tidy;


  xpathCtx = xmlXPathNewContext(doc);
  if(!xpathCtx) {
    flickcurl_error(fc, "Failed to create XPath context for document");
    fc->failed=1;
    goto tidy;
  }

  result=NULL; /* your code here */

  tidy:
  if(xpathCtx)
    xmlXPathFreeContext(xpathCtx);

  if(fc->failed)
    result=NULL;

  return (result == NULL);
}


/**
 * flickcurl_machinetags_getPairs:
 * @fc: flickcurl context
 * @namespace: Limit the list of pairs returned to those that have the following namespace (or NULL)
 * @predicate: Limit the list of pairs returned to those that have the following predicate (or NULL)
 * @per_page: Number of photos to return per page. If this argument is omitted, it defaults to 100. The maximum allowed value is 500 (or NULL)
 * @page: The page of results to return. If this argument is omitted, it defaults to 1 (or NULL)
 * 
 * Return a list of unique namespace and predicate pairs, optionally limited by predicate or namespace, in alphabetical order.
 *
 * Implements flickr.machinetags.getPairs (1.7)
 * 
 * Return value: non-0 on failure
 **/
int
flickcurl_machinetags_getPairs(flickcurl* fc, const char* namespace,
                               const char* predicate,
                               const char* per_page, const char* page)
{
  const char* parameters[11][2];
  int count=0;
  xmlDocPtr doc=NULL;
  xmlXPathContextPtr xpathCtx=NULL; 
  void* result=NULL;
  
  parameters[count][0]  = "namespace";
  parameters[count++][1]= namespace;
  parameters[count][0]  = "predicate";
  parameters[count++][1]= predicate;
  parameters[count][0]  = "per_page";
  parameters[count++][1]= per_page;
  parameters[count][0]  = "page";
  parameters[count++][1]= page;

  parameters[count][0]  = NULL;

  if(flickcurl_prepare(fc, "flickr.machinetags.getPairs", parameters, count))
    goto tidy;

  doc=flickcurl_invoke(fc);
  if(!doc)
    goto tidy;


  xpathCtx = xmlXPathNewContext(doc);
  if(!xpathCtx) {
    flickcurl_error(fc, "Failed to create XPath context for document");
    fc->failed=1;
    goto tidy;
  }

  result=NULL; /* your code here */

  tidy:
  if(xpathCtx)
    xmlXPathFreeContext(xpathCtx);

  if(fc->failed)
    result=NULL;

  return (result == NULL);
}


/**
 * flickcurl_machinetags_getPredicates:
 * @fc: flickcurl context
 * @namespace: Limit the list of predicates returned to those that have the following namespace. (or NULL)
 * @per_page: Number of photos to return per page. If this argument is omitted, it defaults to 100. The maximum allowed value is 500. (or NULL)
 * @page: The page of results to return. If this argument is omitted, it defaults to 1. (or NULL)
 * 
 * Return a list of unique predicates, optionally limited by a given namespace.
 *
 * Implements flickr.machinetags.getPredicates (1.7)
 * 
 * Return value: non-0 on failure
 **/
int
flickcurl_machinetags_getPredicates(flickcurl* fc, const char* namespace,
                                    const char* per_page, const char* page)
{
  const char* parameters[10][2];
  int count=0;
  xmlDocPtr doc=NULL;
  xmlXPathContextPtr xpathCtx=NULL; 
  void* result=NULL;
  
  parameters[count][0]  = "namespace";
  parameters[count++][1]= namespace;
  parameters[count][0]  = "per_page";
  parameters[count++][1]= per_page;
  parameters[count][0]  = "page";
  parameters[count++][1]= page;

  parameters[count][0]  = NULL;

  if(flickcurl_prepare(fc, "flickr.machinetags.getPredicates", parameters, count))
    goto tidy;

  doc=flickcurl_invoke(fc);
  if(!doc)
    goto tidy;


  xpathCtx = xmlXPathNewContext(doc);
  if(!xpathCtx) {
    flickcurl_error(fc, "Failed to create XPath context for document");
    fc->failed=1;
    goto tidy;
  }

  result=NULL; /* your code here */

  tidy:
  if(xpathCtx)
    xmlXPathFreeContext(xpathCtx);

  if(fc->failed)
    result=NULL;

  return (result == NULL);
}


/**
 * flickcurl_machinetags_getValues:
 * @fc: flickcurl context
 * @namespace: The namespace that all values should be restricted to.
 * @predicate: The predicate that all values should be restricted to.
 * @per_page: Number of photos to return per page. If this argument is omitted, it defaults to 100. The maximum allowed value is 500. (or NULL)
 * @page: The page of results to return. If this argument is omitted, it defaults to 1. (or NULL)
 * 
 * Return a list of unique values for a namespace and predicate.
 *
 * Implements flickr.machinetags.getValues (1.7)
 * 
 * Return value: non-0 on failure
 **/
int
flickcurl_machinetags_getValues(flickcurl* fc, const char* namespace,
                                const char* predicate,
                                const char* per_page, const char* page)
{
  const char* parameters[11][2];
  int count=0;
  xmlDocPtr doc=NULL;
  xmlXPathContextPtr xpathCtx=NULL; 
  void* result=NULL;
  
  if(!namespace || !predicate)
    return 1;

  parameters[count][0]  = "namespace";
  parameters[count++][1]= namespace;
  parameters[count][0]  = "predicate";
  parameters[count++][1]= predicate;
  parameters[count][0]  = "per_page";
  parameters[count++][1]= per_page;
  parameters[count][0]  = "page";
  parameters[count++][1]= page;

  parameters[count][0]  = NULL;

  if(flickcurl_prepare(fc, "flickr.machinetags.getValues", parameters, count))
    goto tidy;

  doc=flickcurl_invoke(fc);
  if(!doc)
    goto tidy;


  xpathCtx = xmlXPathNewContext(doc);
  if(!xpathCtx) {
    flickcurl_error(fc, "Failed to create XPath context for document");
    fc->failed=1;
    goto tidy;
  }

  result=NULL; /* your code here */

  tidy:
  if(xpathCtx)
    xmlXPathFreeContext(xpathCtx);

  if(fc->failed)
    result=NULL;

  return (result == NULL);
}
