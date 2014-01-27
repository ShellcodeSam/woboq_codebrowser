/****************************************************************************
 * Copyright (C) 2012-2014 Woboq GmbH
 * Olivier Goffart <contact at woboq.com>
 * http://woboq.com/codebrowser.html
 *
 * This file is part of the Woboq Code Browser.
 *
 * Commercial License Usage:
 * Licensees holding valid commercial licenses provided by Woboq may use
 * this file in accordance with the terms contained in a written agreement
 * between the licensee and Woboq.
 * For further information see http://woboq.com/codebrowser.html
 *
 * Alternatively, this work may be used under a Creative Commons
 * Attribution-NonCommercial-ShareAlike 3.0 (CC-BY-NC-SA 3.0) License.
 * http://creativecommons.org/licenses/by-nc-sa/3.0/deed.en_US
 * This license does not allow you to use the code browser to assist the
 * development of your commercial software. If you intent to do so, consider
 * purchasing a commercial licence.
 ****************************************************************************/

#pragma once

#include <string>
#include <map>
#include <clang/Basic/SourceLocation.h>

namespace clang {
class Preprocessor;
}

class Generator;

class CommentHandler {
    struct CommentVisitor;
public:

    std::multimap<std::string, std::string> docs;

    // fileId -> [ref, global_visibility]
    std::multimap<clang::SourceLocation, std::pair<std::string, bool>> decl_offsets;

    /**
     * Handle the comment startig at @a commentstart within bufferStart with lenght @a len.
     * Search for corresponding declaration in the given source location interval
     */
    void handleComment(Generator& generator, clang::Preprocessor & PP,
                       const char* bufferStart, int commentStart, int len,
                       clang::SourceLocation searchLocBegin, clang::SourceLocation searchLocEnd);

};