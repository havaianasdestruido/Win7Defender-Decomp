# Recovered COM type-library declarations

Source: `TYPELIB/1/1033`, file offset `0xd130`, RVA `0xf530`, size 5848. All member offsets below are relative to that resource. Format interpretation: Wine MSFT typelib records; raw values and provenance are in resource-details.json. Metadata declarations are verified bytes interpreted via that format, **not proof of implementation behavior**. No Windows LoadTypeLib cross-check has been performed.

Library `MpComExportsLib`, LIBID `8c389764-f036-48f2-9ae2-88c260dcf43b`.

`PTR(T)` is typelib pointer indirection (not a C spelling). IUnknown/IDispatch VARTYPEs are already interface-pointer types. `external_hreftype_N` remains unresolved rather than guessed to be a GUID. Callconv=4 is CC_STDCALL metadata; the native x64 ABI still uses Windows x64 calling rules. Parameter flags: 1=in, 2=out, 8=retval; 10=out|retval.

## MsMpComFactoryHome

Kind `coclass`; GUID `a2d75874-6750-4931-94c1-c99d3bc9d0c7`; size 8; vtable bytes 0; record offset `0x16c`.


## IMsMpComFactory

Kind `dispatch`; GUID `ac30c2ba-0109-403d-9d8e-140bb470379c`; size 8; vtable bytes 96; record offset `0x1d0`.

- `HRESULT CreateNativeInstance(PTR(external_hreftype_13) riid [flags=1], PTR(IUnknown) ppObject [flags=10])`; DISPID 1, vtable byte offset 56, callconv 4, record `0x11d4`.
- `HRESULT CreateAutoInstance(BSTR bstrIID [flags=1], PTR(IDispatch) ppObject [flags=10])`; DISPID 2, vtable byte offset 64, callconv 4, record `0x120c`.
- `HRESULT IsElevatedMoniker(PTR(VARIANT_BOOL) pfValue [flags=10])`; DISPID 3, vtable byte offset 72, callconv 4, record `0x1244`.
- `HRESULT AuthChallenge(PTR(VARIANT) pVar [flags=10])`; DISPID 4, vtable byte offset 80, callconv 4, record `0x1270`.
- `HRESULT AuthResponse(VARIANT aVar [flags=1])`; DISPID 5, vtable byte offset 88, callconv 4, record `0x129c`.

## MsMpComFactoryJamaica

Kind `coclass`; GUID `546bf232-c9dd-4f28-8e38-30ae2d964d46`; size 8; vtable bytes 0; record offset `0x234`.


## MsMpComFactoryOneCare

Kind `coclass`; GUID `7007dd05-9412-4939-bcb2-0e6281669a6e`; size 8; vtable bytes 0; record offset `0x298`.


## MsMpComFactoryCallisto

Kind `coclass`; GUID `b8979202-382f-483c-bd2e-89b05e97144b`; size 8; vtable bytes 0; record offset `0x2fc`.


## MsMpClientUtils

Kind `coclass`; GUID `b1da0f88-81e1-43fb-86a6-7cf149404177`; size 8; vtable bytes 0; record offset `0x360`.


## IMsMpClientUtils

Kind `dispatch`; GUID `e2d74550-8e41-460e-bb51-52e1f9522134`; size 8; vtable bytes 144; record offset `0x3c4`.

- `HRESULT QuarantineRemove(PTR(external_hreftype_25) aQuarantineGuid [flags=1])`; DISPID 1, vtable byte offset 56, callconv 4, record `0x1308`.
- `HRESULT QuarantineRemoveAll()`; DISPID 2, vtable byte offset 64, callconv 4, record `0x1334`.
- `HRESULT QuarantineRestore(PTR(external_hreftype_37) aQuarantineGuid [flags=1])`; DISPID 3, vtable byte offset 72, callconv 4, record `0x1354`.
- `HRESULT ThreatHistoryRemoveAll()`; DISPID 4, vtable byte offset 80, callconv 4, record `0x1380`.
- `HRESULT AutoScanCancel()`; DISPID 5, vtable byte offset 88, callconv 4, record `0x13a0`.
- `HRESULT AutoScanPause()`; DISPID 6, vtable byte offset 96, callconv 4, record `0x13c0`.
- `HRESULT AutoScanResume()`; DISPID 7, vtable byte offset 104, callconv 4, record `0x13e0`.
- `HRESULT CreateElevationHandle(PTR(VARIANT) pVarHandleGuid [flags=10])`; DISPID 10, vtable byte offset 112, callconv 4, record `0x1400`.
- `HRESULT ActivateElevationHandle()`; DISPID 11, vtable byte offset 120, callconv 4, record `0x142c`.
- `HRESULT SigUpdateControl(UI4 dwUpdateControl [flags=0])`; DISPID 12, vtable byte offset 128, callconv 4, record `0x144c`.
- `HRESULT AddUserReadAccessToSample(BSTR bstrSample [flags=1], VARIANT varUserSid [flags=1])`; DISPID 13, vtable byte offset 136, callconv 4, record `0x1478`.

## MsMpSimpleConfig

Kind `coclass`; GUID `07dd3249-a591-4949-8f20-09cd347c69dc`; size 8; vtable bytes 0; record offset `0x428`.


## IMsMpSimpleConfig

Kind `dispatch`; GUID `cdfed399-7999-4309-b064-1ede04bc580d`; size 8; vtable bytes 80; record offset `0x48c`.

- `HRESULT ReadValue(BSTR bstrKeyName [flags=1], BSTR bstrValueName [flags=1], PTR(_MP_COM_CONFIG_TYPE) pType [flags=2], PTR(VARIANT) varValue [flags=2])`; DISPID 1, vtable byte offset 56, callconv 4, record `0x1538`.
- `HRESULT WriteValue(BSTR bstrKeyName [flags=1], BSTR bstrValueName [flags=1], _MP_COM_CONFIG_TYPE eType [flags=1], VARIANT varValue [flags=1])`; DISPID 2, vtable byte offset 64, callconv 4, record `0x1588`.
- `HRESULT DeleteValue(BSTR bstrKeyName [flags=1], BSTR bstrValueName [flags=1])`; DISPID 3, vtable byte offset 72, callconv 4, record `0x15d8`.

## _MP_COM_CONFIG_TYPE

Kind `enum`; GUID `None`; size 4; vtable bytes 0; record offset `0x4f0`.

- `MP_COM_CONFIG_TYPE_NONE = 0`; record `0x1638`.
- `MP_COM_CONFIG_TYPE_DWORD = 1`; record `0x164c`.
- `MP_COM_CONFIG_TYPE_SZ = 2`; record `0x1660`.
- `MP_COM_CONFIG_TYPE_MULTI_SZ = 3`; record `0x1674`.
- `MP_COM_CONFIG_TYPE_BINARY = 4`; record `0x1688`.
