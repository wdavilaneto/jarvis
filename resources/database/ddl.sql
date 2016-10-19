create table activation_function (
    id integer primary key,
    name text not null
);

create table neural_network (
    id integer PRIMARY KEY,
    name text not null ,
    num_layers integer not null,
    num_input integer not null ,
    num_hidden integer not null ,
    num_output integer not null,
    desired_error numeric not null,
    max_epochs integer ,
    epochs_between_reports integer,
    activation_hidden integer REFERENCES activation_function(id) ,
    activation_output integer  REFERENCES activation_function(id) ,
    trained text
);
-- ALTER TABLE neural_network ADD trained text;

--drop table corpus;
create table corpus (
    id integer PRIMARY KEY,
    name text not null unique,
    language TEXT
);

--drop table word;
create table word (
    id integer primary key,
    corpus_id integer references corpus(id),
    name text not null unique,
    total integer not null default 0,
    isStop boolean default false
);

--drop table document;
create table document (
    id integer PRIMARY KEY,
    corpus_id integer references corpus(id),
    ref_id integer,
    words_json text
);

--drop table word_document;
--create table word_document (
--    id integer PRIMARY KEY,
--    word_id integer references word(id),
--    doc_id text REFERENCES document(uuid),
--    count integer
--);
--drop table word_form;
create table word_form (
    id integer primary key,
    word_id integer not null references word (id),
    form text
);


-- TODO STEM tabel and STEMMING TYPES (ADJ (ATION ITY MENT..)...)