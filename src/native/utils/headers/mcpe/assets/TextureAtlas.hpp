#pragma once

class AtlasItemManager {
    void dump(std::__ndk1::vector<ParsedAtlasNode, std::__ndk1::allocator<ParsedAtlasNode>> const&, std::__ndk1::basic_ostream<char, std::__ndk1::char_traits<char>>&) const;
    void getTextureItem(std::__ndk1::basic_string<char, std::__ndk1::char_traits<char>, std::__ndk1::allocator<char>> const&) const;
};
class TextureAtlas {
    AtlasItemManager manager;
};