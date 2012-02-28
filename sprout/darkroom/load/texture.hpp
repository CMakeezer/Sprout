
#ifndef DARKROOM_DEF_LOAD_TEXTURE_IDENTIFIER
#	error should define DARKROOM_DEF_LOAD_TEXTURE_IDENTIFIER.
#endif

#ifndef DARKROOM_DEF_LOAD_TEXTURE_FILE
#	error should define DARKROOM_DEF_LOAD_TEXTURE_FILE.
#endif

#define DARKROOM_LOAD_IDENTIFIER_DETAIL_CAT(id, suffix) DARKROOM_LOAD_IDENTIFIER_DETAIL_CAT_I(id, suffix)
#define DARKROOM_LOAD_IDENTIFIER_DETAIL_CAT_I(id, suffix) DARKROOM_LOAD_IDENTIFIER_DETAIL_CAT_II(id ## suffix)
#define DARKROOM_LOAD_IDENTIFIER_DETAIL_CAT_II(res) res

#define DARKROOM_LOAD_IDENTIFIER DARKROOM_DEF_LOAD_TEXTURE_IDENTIFIER
#define DARKROOM_LOAD_DETAIL_IDENTIFIER(id) DARKROOM_LOAD_IDENTIFIER_DETAIL_CAT( \
	DARKROOM_LOAD_IDENTIFIER_DETAIL_CAT(DARKROOM_DEF_LOAD_TEXTURE_IDENTIFIER, id), \
	_darkroom_load_texture_detail \
	)

SPROUT_STATIC_CONSTEXPR sprout::darkroom::textures::version_type DARKROOM_LOAD_DETAIL_IDENTIFIER(version) =
#	define DARKROOM_LOADING_TEXTURE_VERSION
#	include DARKROOM_DEF_LOAD_TEXTURE_FILE
#	undef DARKROOM_LOADING_TEXTURE_VERSION
	;
SPROUT_STATIC_CONSTEXPR sprout::darkroom::textures::info_type DARKROOM_LOAD_DETAIL_IDENTIFIER(info) = {
#	define DARKROOM_LOADING_TEXTURE_INFO
#	include DARKROOM_DEF_LOAD_TEXTURE_FILE
#	undef DARKROOM_LOADING_TEXTURE_INFO
	};

SPROUT_STATIC_CONSTEXPR sprout::darkroom::textures::image_type<
	DARKROOM_LOAD_DETAIL_IDENTIFIER(info).width,
	DARKROOM_LOAD_DETAIL_IDENTIFIER(info).height
> DARKROOM_LOAD_IDENTIFIER(
	DARKROOM_LOAD_DETAIL_IDENTIFIER(info).image_format,
	DARKROOM_LOAD_DETAIL_IDENTIFIER(info).pixel_format,
#	define DARKROOM_LOADING_TEXTURE_PIXEL
#	include DARKROOM_DEF_LOAD_TEXTURE_FILE
#	undef DARKROOM_LOADING_TEXTURE_PIXEL
	);

#undef DARKROOM_LOAD_IDENTIFIER
#undef DARKROOM_LOAD_DETAIL_IDENTIFIER

#undef DARKROOM_LOAD_IDENTIFIER_DETAIL_CAT
#undef DARKROOM_LOAD_IDENTIFIER_DETAIL_CAT_I
#undef DARKROOM_LOAD_IDENTIFIER_DETAIL_CAT_II

#undef DARKROOM_DEF_LOAD_TEXTURE_IDENTIFIER
#undef DARKROOM_DEF_LOAD_TEXTURE_FILE