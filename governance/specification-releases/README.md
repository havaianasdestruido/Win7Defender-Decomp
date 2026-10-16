# Specification release records

A `REL-*.json` record is created by the clean specification exporter for every
package delivered to Team B. It records exact specification revisions and
hashes, package-manifest and archive hashes, recipient, transfer coordinator,
and delivery status.

Release records are analyst-side governance evidence and are not included in
the clean package. They contain no raw analysis evidence. The template is not a
release record and is ignored by the validator.
