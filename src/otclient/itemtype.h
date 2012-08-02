/*
 * Copyright (c) 2010-2012 OTClient <https://github.com/edubart/otclient>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */


#ifndef ITEMTYPE_H
#define ITEMTYPE_H

#include <framework/core/declarations.h>
#include <framework/luaengine/luaobject.h>
#include <framework/xml/tinyxml.h>

enum ItemCategory {
    ItemCategoryInvalid      = 0,
    ItemCategoryGround       = 1,
    ItemCategoryContainer    = 2,
    ItemCategoryWeapon       = 3,
    ItemCategoryAmmunition   = 4,
    ItemCategoryArmor        = 5,
    ItemCategoryCharges      = 6,
    ItemCategoryTeleport     = 7,
    ItemCategoryMagicField   = 8,
    ItemCategoryWritable     = 9,
    ItemCategoryKey          = 10,
    ItemCategorySplash       = 11,
    ItemCategoryFluid        = 12,
    ItemCategoryDoor         = 13,
    ItemCategoryLast         = 14
};

enum ItemTypeAttr : uint8 {
    ItemTypeAttrServerId         = 16,
    ItemTypeAttrClientId         = 17,
    ItemTypeAttrName             = 18,   // deprecated
    ItemTypeAttrDesc             = 19,   // deprecated
    ItemTypeAttrSpeed            = 20,
    ItemTypeAttrSlot             = 21,   // deprecated
    ItemTypeAttrMaxItems         = 22,   // deprecated
    ItemTypeAttrWeight           = 23,   // deprecated
    ItemTypeAttrWeapon           = 24,   // deprecated
    ItemTypeAttrAmmunition       = 25,   // deprecated
    ItemTypeAttrArmor            = 26,   // deprecated
    ItemTypeAttrMagicLevel       = 27,   // deprecated
    ItemTypeAttrMagicField       = 28,   // deprecated
    ItemTypeAttrWritable         = 29,   // deprecated
    ItemTypeAttrRotateTo         = 30,   // deprecated
    ItemTypeAttrDecay            = 31,   // deprecated
    ItemTypeAttrSpriteHash       = 32,
    ItemTypeAttrMinimapColor     = 33,
    ItemTypeAttr07               = 34,
    ItemTypeAttr08               = 35,
    ItemTypeAttrLight            = 36,
    ItemTypeAttrDecay2           = 37,   // deprecated
    ItemTypeAttrWeapon2          = 38,   // deprecated
    ItemTypeAttrAmmunition2      = 39,   // deprecated
    ItemTypeAttrArmor2           = 40,   // deprecated
    ItemTypeAttrWritable2        = 41,   // deprecated
    ItemTypeAttrLight2           = 42,
    ItemTypeAttrTopOrder         = 43,
    ItemTypeAttrWrtiable3        = 44,   // deprecated
    ItemTypeAttrLast             = 45
};

class ItemType : public LuaObject
{
public:
    ItemType();

    void unserialize(const BinaryTreePtr& node);

    uint16 getServerId() { return m_attribs.get<uint16>(ItemTypeAttrServerId); }
    uint16 getClientId() { return m_attribs.get<uint16>(ItemTypeAttrClientId); }
    ItemCategory getCategory() { return m_category; }
    std::string getName() { return m_attribs.get<std::string>(ItemTypeAttrName); }
    std::string getDesc() { return m_attribs.get<std::string>(ItemTypeAttrDesc); }

    bool isNull() { return m_null; }

    void setClientId(uint16 clientId) { m_attribs.set(ItemTypeAttrClientId, clientId); }
    void setServerId(uint16 serverId) { m_attribs.set(ItemTypeAttrServerId, serverId); }
    void setName(const std::string& name) { m_attribs.set(ItemTypeAttrName, name); }
    void setDesc(const std::string& desc) { m_attribs.set(ItemTypeAttrDesc, desc); }

private:
    ItemCategory m_category;
    stdext::boolean<true> m_null;

    stdext::dynamic_storage<uint8> m_attribs;
};

#endif