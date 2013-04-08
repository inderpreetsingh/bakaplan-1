/*
 * ===================================================================
 *
 *       Filename:  detail.h
 *
 *    Description:  Base class for all common variable declaration and
 *                  functions that are used by derived classes
 *
 *        Version:  0.6
 *        Created:  Friday 22 February 2013 11:34:29  IST
 *       Compiler:  gcc
 *
 *         Author:  Mandeep Kaur, meghasimak@gmail.com
 *        License:  GNU General Public License
 *      Copyright:  Copyright (c) 2013, Great Developers
 *
 * ===================================================================
 */

#ifndef INPUTDETAIL_H
#define INPUTDETAIL_H

/**
 *  Include Local header files 
 */

#include "filename.h"                            /* I/O  File Names */
#include "pagelayout.h"                         /* PageLayout Class */
#include "inputfieldname.h"                 /* InputFieldName Class */
#include "readinputfield.h"                 /* ReadInputField Class */
#include "constant.h"                   /* Constants for array size */
#include "database.h"                  /* For database connectivity */

/**
 *      \class  InputDetail
 *      \brief  Declare common variables, functions that are used by
 *              derived class.
 */

class InputDetail //: public PageLayout
{
    protected:
        /* Common variables and objects */
        
        /* Objects of InputFieldName and ReadFieldsValue class  */

        InputFieldName fieldName;               /**< I/P field name */
        ReadInputField readField;               /**< Read I/P Field */
        Database database;                   /**< Accecing Database */
        PageLayout page;                             /**< HTML Tags */
        
        int i, j, k, l;                      /**< Looping Variables */

        stringstream ss;          /**< for converting int to string */
        string temp;                    /**< for temporary strorage */
        // For project detail
        string projectID,                           /**< Project ID */
               emailID,                               /**< Email id */
               projectName;                       /**< Project Name */

        string fileName,            /**< file name for opening file */
               where,                     /**< Temp variable to store 
                                                       where clause */
               msg;                   /**< For Displaying error msg */

        STRING_VEC vecTemp,        /**< string Vector temporary use */
                   oldProject;                 /**< For stroring old
                                                    projects if any */
 
        ifstream inFile;                      /**< For Reading file */
        ofstream outFile;                     /**< For writing file */
        string sessionID;                       /**< Session ID */

    public:
        Database data;
        InputDetail();       
        void Header(string titleName);
        void Footer();
        string IntToString(int value);
        
        /// Convert String to Integer
        int StringToInt(string value);

        /** Shows message if user filled data in field */
        void ErrorMessage(string msg = "");

        /** For locating current time on system */
        string Time();
};

#endif
