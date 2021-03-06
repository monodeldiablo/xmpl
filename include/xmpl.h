/* xmpl.h
 *
 * This is a convenience library that wraps much of the functionality of the
 * exempi library. I wrote this for three reasons:
 * 
 * 1) I was having serious issues wrapping exempi/xmp.h directly with Vala
 *    because it is written with named pointers (XmpFilePtr, XmpPtr, etc.) that
 *    reference structs, and this lack of naming consistency confuses Vala
 *    (e.g. it wants to send a pointer to the XmpPtr instance to the xmp_free()
 *    function, but that function only accepts an XmpPtr (which is itself a
 *    pointer to the Xmp struct).
 *
 * 2) A lack of internet access (this was written in a $6 hotel room in
 *    Sonsonate, El Salvador... largely due to the fact that a congregation of
 *    rats has kept me up until daybreak) prevented me from troubleshooting the
 *    above issue on my own and coming up with a clean, pretty, simple, and
 *    reusable implementation that I could then donate to the community (sorry
 *    folks).
 *
 * 3) For the purposes of Snap, only a subset of exempi's functionality is
 *    currently used. "Waste not, want not" and all that jazz...
 *
 * Because, in Snap's case, all of the input is coming from a UI that is
 * ignorant of any types other than strings (most likely), this library
 * attempts to make a guess at what the caller means when they send in a value.
 * This means that goofy types, like arrays, are denoted by strings of words,
 * joined by commas (e.g. "this,is,an,array,of strings"). Hopefully, this
 * guessing is reasonably safe and rare.
 */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <exempi/xmp.h>
#include <exempi/xmpconsts.h>

/* These are a few common namespaces used in RAW and JPEG images, so you     *
 * don't have to remember a bunch of esoteric URIs. You're welcome.          */
const char* XMPL_DC = NS_DC;
const char* XMPL_CC = NS_CC;
const char* XMPL_EXIF = NS_EXIF;
const char* XMPL_EXIF_AUX = NS_EXIF_AUX;
const char* XMPL_TIFF = NS_TIFF;
const char* XMPL_RDF = NS_RDF;
const char* XMPL_XMP = NS_XMP_META;
const char* XMPL_XAP = NS_XAP;
const char* XMPL_XAP_RIGHTS = NS_XAP_RIGHTS;

/* Given a file and a property name (e.g. 'creator' or 'subject'), this will *
 * retrieve the property's value. This method will try to guess the type     *
 * and, if it is not a string, will attempt to coerce it into one, free of   *
 * charge.                                                                   */
char* xmpl_get_property (const char* file, const char* namespace, const char* key);

/* Given a file, property name, and value, this will set the property to the *
 * supplied value. It assumes that all input is a string, and tries to set   *
 * the value to the proper type unless it's just not possible, in which case *
 * the method throws up its hands in frustration and resigns itself to       *
 * failure.                                                                  */
bool xmpl_set_property (const char* file, const char* namespace, const char* key, const char* value);

/* And, to complete the trifecta, we have the wholesale carpetbombing        *
 * method, which, given a file and property name, wipes any and all mention  *
 * of that property's value(s) off the map. Boom. Goodbye. Make sure you're  *
 * not being rash before using this guy. He's not the type to ask            *
 * permission.                                                               */
bool xmpl_delete_property (const char* file, const char* namespace, const char* key);
